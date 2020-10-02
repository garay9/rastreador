#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo.h>
#include <math.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/reg.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "names.c"
#include "rastreador.c"

static void do_drawing(cairo_t *);
extern void *hiloTracer(void *vargp);
extern void tracerNormal();

extern char *getname(int syscall);
extern char *getDescription(int syscall);
extern int continuar;
extern int ejecucionContinua;
extern int argNumber;
extern char **args;
extern char **bitacora;
extern char ***tablaAcumulada;
extern char ***tablaBitacora;
extern int sizeBitacora;
extern int contadorTabla;
extern int rows;
extern int cols;
extern int tableSize;
extern int cargarLinea;
extern int terminado;
extern int error;

GtkWidget *bitacoraScrolled;

GtkWidget *darea;
GtkWidget *pausada_radio;
GtkWidget *continua_radio;
GtkWidget *rastrear_button;
GtkWidget *reset_button;
GtkWidget *next_button;
GtkWidget *consolaField;
GtkWidget *exit_button;
GtkWidget *dialogWindow;
GtkButton *dialogButton;
GtkContainer *dialogBox;
GtkButtonBox *buttonBox;
GtkLabel *dialogLabel;

GtkFixed *contenedor;
GtkWidget *chartArea;

GtkViewport *bitacoraViewPort;
GtkTreeView *bitacoraTreeView;
GtkListStore *bitacoraStore;
GtkTreeSelection *selection;

GtkTreeViewColumn *secuenciaColumn;
GtkTreeViewColumn *codigoColumn;
GtkTreeViewColumn *nombreColumn;
GtkTreeViewColumn *descripcionColumn;

GtkCellRenderer *secuenciaText;
GtkCellRenderer *codigoText;
GtkCellRenderer *nombreText;
GtkCellRenderer *descripcionText;

GtkViewport *acumuladaViewPort;
GtkTreeView *acumuladaTreeView;
GtkListStore *acumuladaStore;
GtkTreeSelection *acumuldadSelection;

GtkTreeViewColumn *nombreColumnF;
GtkTreeViewColumn *frecuenciaColumn;

GtkCellRenderer *nombreTextF;
GtkCellRenderer *frecuenciaText;

GtkWidget *window;
GtkBuilder *builder;

int maxSizeBitacora = 1024;
int maxSizeFrecuencia = 1024;
int widthChart = 600;
int heightChart = 520;
int currentRow = 1;

int pausadaStarted;

int value = -1;

float calcularSuma()
{
    int suma = 0;
    for (int i = 0; i < tableSize; i++)
    {
        //     const gint str = atoi(tablaAcumulada[i][j]);
        suma += atoi(tablaAcumulada[i][1]);
    }
    return suma;
}

void showDialog()
{
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label;

    gint response_id;

    dialog = gtk_dialog_new_with_buttons("oOoPS mi pana.",
                                         window,
                                         GTK_DIALOG_MODAL,
                                         "pum pum pum",
                                         GTK_RESPONSE_OK,
                                         NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    label = gtk_label_new("Por favor ingrese un programa usando la línea de comandos.");
    gtk_container_add(GTK_CONTAINER(content_area), label);

    gtk_widget_show_all(dialog);

    g_signal_connect(GTK_DIALOG(dialog), "response", G_CALLBACK(gtk_widget_destroy), NULL);
}

//Muestra la tabla de acumulados
void desplegarTablaAcumulada()
{
    GtkTreeIter iter;
    gtk_list_store_clear(acumuladaStore);

    for (int i = 0; i < tableSize; i++)
    {
        gtk_list_store_append(acumuladaStore, &iter);
        for (int j = 0; j < 2; j++)
        {
            //si es data[i][1], se obtiene la frecuencia
            if (j == 1)
            {
                const gint str = atoi(tablaAcumulada[i][j]);

                gtk_list_store_set(acumuladaStore, &iter, j, str, -1);
            }
            else
            {
                const gchararray str = tablaAcumulada[i][j];
                gtk_list_store_set(acumuladaStore, &iter, j, str, -1);
            }
        }
    }
    gtk_main_iteration();
}

void desplegarBitacoraPausada(char **array)
{
    if (!terminado)
    {
        while (!cargarLinea)
            if (terminado)
                return;
        ;
        cargarLinea = 0;
        GtkTreeIter iter;

        gtk_list_store_append(bitacoraStore, &iter);

        for (int i = 0; i < cols; i++)
        {
            const gchararray str = array[i];
            gtk_list_store_set(bitacoraStore, &iter, i, str, -1);
        }
        cargarLinea = 0;
    }
    else
    {
        gtk_widget_set_sensitive(next_button, FALSE);
    }
}

void addLineaBitacora()
{
    if (cargarLinea)
    {
        GtkTreeIter iter;
        if (sizeBitacora > 1000)
        {
            GtkTreeIter iter2;
            gtk_list_store_prepend(bitacoraStore, &iter2);
            gtk_list_store_remove(bitacoraStore, &iter2);
            gtk_list_store_remove(bitacoraStore, &iter2);
        }
        gtk_list_store_append(bitacoraStore, &iter);

        for (int j = 0; j < cols; j++)
        {
            const gchararray str = tablaBitacora[sizeBitacora - 1][j];
            gtk_list_store_set(bitacoraStore, &iter, j, str, -1);
        }
    }
    gtk_main_iteration();
}

/*********************************************
******************GLADE EVENTS****************
**********************************************/

int isEmpty()
{
    int len = gtk_entry_get_text_length(consolaField);
    if (len == 0)
        return 1;
    else
        return 0;
}

void update()
{
    while (gtk_events_pending())
    {
        gtk_main_iteration();
    }
}

void exit_button_clicked_cb(GtkButton *b)
{
    exit(1);
}

void continua_radio_toggled_cb(GtkToggleButton *continua_radio)
{

    ejecucionContinua = 1;
    continuar = 1;
}

void pausada_radio_toggled_cb(GtkToggleButton *pausada_radio)
{
    ejecucionContinua = 0;
    continuar = 1;
}

void next_button_clicked_cb(GtkButton *b)
{
    continuar = 1;
    desplegarBitacoraPausada(bitacora);
    desplegarTablaAcumulada();
    if (terminado)
    {
        gtk_widget_set_sensitive(next_button, FALSE);
        loadChart();
    }
}

void rastrear_button_clicked_cb(GtkButton *rastrear_button)
{
    gtk_widget_set_sensitive(reset_button, FALSE);
    if (isEmpty())
    {
        showDialog();
    }
    else
    {
        if (!ejecucionContinua)
        {

            gtk_widget_set_sensitive(next_button, TRUE);
            continuar = 1;
        }
        else
        {
            gtk_widget_set_sensitive(next_button, FALSE);
        }

        char *comando = gtk_entry_get_text(consolaField);
        int maxArgc = 20;
        int argc = 0;
        char **argumentos = (char **)malloc(maxArgc * sizeof(char *));
        for (int j = 0; j < maxArgc; j++)
        {
            argumentos[j] = malloc(255 * sizeof(char));
            char *token;

            token = strtok_r(comando, " ", &comando);
            if (token == NULL)
                break;
            strcpy(argumentos[j], token);
            argc++;
        }
        args = argumentos;
        argNumber = argc;
        if (!ejecucionContinua)
        {
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, hiloTracer, NULL);
        }
        else
        {
            tracerNormal();
        }
        gtk_widget_set_sensitive(reset_button, TRUE);
        continuar = 1;
        loadChart();
        
    }
}

void reset_button_clicked_cb(GtkButton *b)
{
    gtk_list_store_clear(bitacoraStore);
    gtk_list_store_clear(acumuladaStore);
    gtk_widget_set_sensitive(next_button, FALSE);
    continuar = 0;
    contadorTabla = 0;
    sizeBitacora = 0;
    tableSize = 0;
    cargarLinea = 0;
    terminado = 0;
    error = 0;
    gtk_widget_hide(chartArea);
    for (int j = 0; j < 4; j++)
    {
        free(bitacora[j]);
    }
    free(bitacora);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            free(tablaAcumulada[i][j]);
        }
        free(tablaAcumulada[i]);
    }
    free(tablaAcumulada);
    for (int i = 0; i < rows * 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            free(tablaBitacora[i][j]);
        }
        free(tablaBitacora[i]);
    }
    free(tablaBitacora);
}

void dialogButton_clicked_cb(GtkButton *b)
{
    gtk_window_close(dialogWindow);
}

/******************************************************************
 *****************************DRAW CHART***************************
******************************************************************/
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data);

struct
{
    int count;
    double coordx[100];
    double coordy[100];
} glob;

static void do_drawing(cairo_t *cr)
{

    float toAngle = M_PI * 5 / 3;
    float fromAngle = toAngle;

    srand(time(NULL));
    cairo_set_line_width(cr, 9);
    float Suma = calcularSuma();
    if (Suma == 0)
        return;

    float blue = 15;
    for (int i = 0; i < rows; i++)
    {
        float p = atoi(tablaAcumulada[i][1]);

        p /= Suma;

        toAngle += 2 * M_PI * p;
        cairo_set_source_rgb(cr, 17.0 / 255.0, 136.0 / 255.0, blue / 255.0);
        cairo_arc(cr, widthChart / 2, widthChart / 2, widthChart * 0.45, fromAngle, toAngle);
        cairo_line_to(cr, widthChart / 2, heightChart / 2);
        cairo_fill(cr);
        fromAngle = toAngle;
        blue -= 30;
        if (blue <= 0)
        {
            blue = 255;
        }
    }

    toAngle = M_PI * 5 / 3;
    fromAngle = toAngle;
    for (int i = 0; i < rows; i++)
    {
        float p = atoi(tablaAcumulada[i][1]);
        p /= Suma;

        if (p > 0.01)
        {
            toAngle += 2 * M_PI * p;
            float angle = (fromAngle + toAngle) / 2;
            float labelX = widthChart / 2 * (0.8 + 0.7 * cos(angle));
            float labelY = widthChart / 2 * (1 + 0.7 * sin(angle));
            cairo_set_source_rgb(cr, 1, 1, 1);
            cairo_move_to(cr, labelX, labelY);
            char labelPercent[128];
            float percent = p * 100;
            snprintf(labelPercent, sizeof(labelPercent), "%.2f", percent);
            strcat(labelPercent, "%  ");
            strcat(labelPercent, tablaAcumulada[i][0]);
            cairo_show_text(cr, labelPercent);
            cairo_fill(cr);
            fromAngle = toAngle;
        }
    }
}

static gboolean clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data)
{
    if (event->button == 1)
    {
        glob.coordx[glob.count] = event->x;
        glob.coordy[glob.count++] = event->y;
    }

    if (event->button == 3)
    {
        gtk_widget_queue_draw(widget);
    }

    return TRUE;
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{

    do_drawing(cr);

    return FALSE;
}

void loadChart()
{
    g_signal_connect(G_OBJECT(chartArea), "draw", G_CALLBACK(on_draw_event), NULL);
    gtk_widget_queue_draw(chartArea);
    gtk_widget_show(chartArea);
    gtk_main();
}

/*************************************************
 * ****************INICIALIZAR COSITAS************
 *************************************************/

void initializeTreeAcumulada()
{

    acumuladaViewPort = GTK_VIEWPORT(gtk_builder_get_object(builder, "acumuladaViewPort"));

    acumuldadSelection = GTK_TREE_SELECTION(gtk_builder_get_object(builder, "selectionTreeView"));

    nombreColumnF = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "nombreColumnF"));
    frecuenciaColumn = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "fecuenciaColumn"));

    nombreTextF = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "nombreTextF"));
    frecuenciaText = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "frecuenciaText"));

    gtk_tree_view_column_add_attribute(nombreColumnF, nombreTextF, "text", 0);
    gtk_tree_view_column_add_attribute(frecuenciaColumn, frecuenciaText, "text", 1);
}

void initializeTreeBitacora()
{

    bitacoraViewPort = GTK_VIEWPORT(gtk_builder_get_object(builder, "bitacoraViewPort"));

    selection = GTK_TREE_SELECTION(gtk_builder_get_object(builder, "selectionTreeView"));

    secuenciaColumn = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "secuenciaColumn"));
    codigoColumn = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "codigoColumn"));
    nombreColumn = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "nombreColumn"));
    descripcionColumn = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "descripcionColumn"));

    secuenciaText = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "secuenciaText"));
    codigoText = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "codigoText"));
    nombreText = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "nombreText"));
    descripcionText = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "descripcionText"));

    gtk_tree_view_column_add_attribute(secuenciaColumn, secuenciaText, "text", 0);
    gtk_tree_view_column_add_attribute(codigoColumn, codigoText, "text", 1);
    gtk_tree_view_column_add_attribute(nombreColumn, nombreText, "text", 2);
    gtk_tree_view_column_add_attribute(descripcionColumn, descripcionText, "text", 3);
}

void initializeMainWindow()
{
    builder = gtk_builder_new_from_file("glade/mainWindow.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));

    gtk_builder_connect_signals(builder, NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GdkColor color;
    gdk_color_parse("#FFFFFF", &color);

    gtk_widget_modify_bg(GTK_WIDGET(window), GTK_STATE_NORMAL, &color);

    bitacoraScrolled = GTK_WIDGET(gtk_builder_get_object(builder, "bitacoraScrolled"));
    gdk_color_parse("#ffffff", &color);
    gtk_widget_modify_bg(GTK_WIDGET(bitacoraScrolled), GTK_STATE_NORMAL, &color);

    contenedor = GTK_FIXED(gtk_builder_get_object(builder, "contenedor"));

    bitacoraTreeView = GTK_TREE_VIEW(gtk_builder_get_object(builder, "bitacoraTreeView"));
    bitacoraStore = GTK_LIST_STORE(gtk_builder_get_object(builder, "bitacoraStore"));

    acumuladaTreeView = GTK_TREE_VIEW(gtk_builder_get_object(builder, "acumuladaTreeView"));
    acumuladaStore = GTK_LIST_STORE(gtk_builder_get_object(builder, "acumuladaStore"));

    continua_radio = GTK_WIDGET(gtk_builder_get_object(builder, "continua_radio"));
    pausada_radio = GTK_WIDGET(gtk_builder_get_object(builder, "pausada_radio"));

    rastrear_button = GTK_WIDGET(gtk_builder_get_object(builder, "rastrear_button"));
    reset_button = GTK_WIDGET(gtk_builder_get_object(builder, "reset_button"));
    next_button = GTK_WIDGET(gtk_builder_get_object(builder, "next_button"));
    gtk_widget_set_sensitive(next_button, FALSE);

    consolaField = GTK_WIDGET(gtk_builder_get_object(builder, "consola_field"));
    exit_button = GTK_WIDGET(gtk_builder_get_object(builder, "exit_button"));
}



int main(int argc, char *argv[])
{
    pausadaStarted = 0;
    ejecucionContinua = 1;
    gtk_init(&argc, &argv);

    //builder = gtk_builder_new();
    // gtk_builder_add_from_file (builder, "glade/mainWindow.glade", NULL);
    // Update October 2019: The line below replaces the 2 lines above

    initializeMainWindow();
    initializeTreeBitacora();
    initializeTreeAcumulada();
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(bitacoraTreeView));

    chartArea = GTK_WIDGET(gtk_builder_get_object(builder, "chartArea"));
    gtk_widget_hide(chartArea);

    g_object_unref(builder);
    gtk_widget_show(window);
    gtk_main();
    /* Release gtk's global lock */
    return 0;
}
// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}