#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <cairo.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
GtkWidget       *bitacoraScrolled;

GtkWidget *pausada_radio;
GtkWidget *continua_radio;
GtkWidget *rastrear_button;
GtkWidget *next_button;
GtkWidget *bitacora_tree;
GtkWidget *consolaField;
GtkWidget *chart_button;
GtkContainer    *Grid;
    GtkWidget       *window;
int widthChart = 600;
int heightChart= 600;
int rows = 100;
int cols = 4;
int currentRow = 1;


int pausadaStarted;

void update(){
	while(gtk_events_pending()){
		gtk_main_iteration_do(10);
	}
}


void continua_radio_toggled_cb(GtkToggleButton *continua_radio){
    gboolean isActive = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(continua_radio));
    printf("%i\n", isActive);
    if(!isActive){
        gtk_widget_set_sensitive (rastrear_button, FALSE);
        gtk_widget_set_sensitive (next_button, TRUE);
    }else{
        gtk_widget_set_sensitive (rastrear_button, TRUE);
        gtk_widget_set_sensitive (next_button, FALSE);

    }
}



void pausada_radio_toggled_cb(GtkToggleButton *pausada_radio){
    printf(":(");
}

void desplegarBitacoraPausada(GtkContainer *grid, char **array){
    for(int i = 0; i < cols; i++){
        const gchar *str = array[i];
        GtkWidget* label = gtk_label_new (str); 
        GdkColor color;
        if(i%2 !=0){
            if(currentRow%2 == 0) 
                gdk_color_parse ("#DBF4F4", &color);
             else 
                gdk_color_parse ("#FFFFFF", &color); 

                
        }else{
            if(currentRow%2 == 0) 
                gdk_color_parse ("#FFFFFF", &color);
            else 
                gdk_color_parse ("#DBF4F4", &color);
                
        }
        gtk_widget_modify_bg ( GTK_WIDGET(label), GTK_STATE_NORMAL, &color);
        gtk_grid_attach (GTK_GRID(grid), label, i, currentRow,1,1);
       
        free(str);

    }
    currentRow++;      
    gtk_widget_show_all(grid);      

}
void desplegarBitacoraContinua(GtkContainer *grid, char ***matrix){

    for(int i = 0;  i < rows ; i++){
        for(int j = 0; j < cols; j++){
        const gchar *str = matrix[i][j];
           GtkWidget* label = gtk_label_new (str); 
            GdkColor color;
            if(j%2 !=0){
                if(i%2 == 0) 
                    gdk_color_parse ("#DBF4F4", &color);
                else 
                    gdk_color_parse ("#FFFFFF", &color); 

                
            }else{
                if(i%2 == 0) 
                    gdk_color_parse ("#FFFFFF", &color);
                else 
                    gdk_color_parse ("#DBF4F4", &color);
                
            }
            gtk_widget_modify_bg ( GTK_WIDGET(label), GTK_STATE_NORMAL, &color);
            gtk_grid_attach (GTK_GRID(grid), label, j, i+1,1,1);
            gtk_widget_show_all(grid); 

            free(str);
        }
  
       
    }

			
		
}



//*********************************************



void next_button_clicked_cb(GtkButton *b, GtkContainer *bitacora_grid){
    char **array = (char**) malloc(4 * 255);
    for(int i = 0; i < 4; i++){
			array[i] = (char*) malloc(255);
            strcpy(array[i], "Holi");
	}
    printf("mmm");
    desplegarBitacoraPausada(bitacora_grid, array);
}

static void do_drawing(cairo_t *,  GtkWidget *widget);

struct {
  int count;
  double coordx[100];
  double coordy[100];
} glob;


static void do_drawing(cairo_t *cr, GtkWidget *widget){
  GtkWidget *win = gtk_widget_get_toplevel(widget);
  float mark[5] = {0.25, 0.10, 0.50, 0.05, 0.10};
  float toAngle = M_PI * 3 / 2;
  float fromAngle = toAngle;  
  
  srand(time(NULL)); 
  cairo_set_line_width(cr, 9);  
  int size = sizeof(mark)/sizeof(mark[0]);

  for(int i = 0; i < size; i++){
      
      toAngle += 2 * M_PI * mark[i];
      cairo_set_source_rgb(cr, rand()%256/100, rand()%256/100, rand()%256/100);
      cairo_arc(cr, widthChart/2, widthChart/2, widthChart * 0.45, fromAngle, toAngle);
      cairo_line_to(cr, widthChart/2, heightChart/2);
      cairo_fill(cr);
      fromAngle = toAngle;

  }
   
}

static gboolean clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data){
    if (event->button == 1) {
        glob.coordx[glob.count] = event->x;
        glob.coordy[glob.count++] = event->y;
    }

    if (event->button == 3) {
        gtk_widget_queue_draw(widget);
    }

    return TRUE;
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data){
  do_drawing(cr, widget);

  return FALSE;
}

void loadChart(){
    GtkWidget       *chartArea;
    GtkWidget       *statisticsWindow;

    statisticsWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    chartArea = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(statisticsWindow), chartArea);

     g_signal_connect(G_OBJECT(chartArea), "draw", 
    G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(G_OBJECT(statisticsWindow), "destroy",
    G_CALLBACK(gtk_main_quit), NULL);

    gtk_window_set_position(GTK_WINDOW(statisticsWindow), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(statisticsWindow), 600, 600); 
    gtk_window_set_title(GTK_WINDOW(statisticsWindow), "Estadísticas");
    gtk_widget_show_all(statisticsWindow);

    gtk_main();

     return 0;
}

int main(int argc, char *argv[])
{

    
    GtkBuilder      *builder; 



   

 

    pausadaStarted = 0;


    gtk_init(&argc, &argv);

     //builder = gtk_builder_new();
    // gtk_builder_add_from_file (builder, "glade/mainWindow.glade", NULL);
    // Update October 2019: The line below replaces the 2 lines above
    builder = gtk_builder_new_from_file("glade/mainWindow.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));


    GdkColor color;
    gdk_color_parse ("#FFFFFF", &color);

    gtk_widget_modify_bg ( GTK_WIDGET(window), GTK_STATE_NORMAL, &color);

    Grid = GTK_CONTAINER(gtk_builder_get_object(builder, "bitacora_grid"));

    continua_radio =  GTK_WIDGET(gtk_builder_get_object(builder, "continua_radio"));
    pausada_radio =  GTK_WIDGET(gtk_builder_get_object(builder, "pausada_radio"));
    
    rastrear_button =  GTK_WIDGET(gtk_builder_get_object(builder, "rastrear_button"));
    next_button =  GTK_WIDGET(gtk_builder_get_object(builder, "next_button"));
    gtk_widget_set_sensitive (next_button, FALSE);

    bitacoraScrolled = GTK_WIDGET(gtk_builder_get_object(builder, "bitacoraScrolled"));
    gdk_color_parse ("#ffffff", &color);
    gtk_widget_modify_bg ( GTK_WIDGET(bitacoraScrolled), GTK_STATE_NORMAL, &color);

    consolaField = GTK_WIDGET(gtk_builder_get_object(builder, "consola_field"));
    chart_button =  GTK_WIDGET(gtk_builder_get_object(builder, "chart_button"));
    gtk_widget_set_sensitive (chart_button, FALSE);

  
    gtk_builder_connect_signals(builder, NULL);

    
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
   g_object_unref(builder);
  
    gtk_widget_show(window);
        
 
    
    //loadChart();                
   gtk_main();

    return 0;
}
void rastrear_button_clicked_cb(GtkButton *b, GtkContainer *bitacora_grid){
    char ***matrix = (char***) malloc(rows * sizeof(char**));
    for(int i = 0; i < rows; i++){
        matrix[i] = (char**) malloc(cols * sizeof(char*));
		for(int j = 0; j < cols; j++){
            matrix[i][j] =  malloc(255 *sizeof(char));
           strcpy(matrix[i][j] , "Hello world"); 
        }

	}
  desplegarBitacoraContinua(bitacora_grid, matrix);  
   
    
}





// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}