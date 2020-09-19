#include <gtk/gtk.h>
#include <gdk/gdk.h>

GtkWidget *pausada_radio;
GtkWidget *continua_radio;
GtkWidget *rastrear_button;
GtkWidget *next_button;
GtkWidget *bitacora_tree;



int pausadaStarted;

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

void desplegarMarik(GtkContainer *grid){
    /*	GtkWidget* botones [6][4];
        for(int i = 0; i < 6 ; i++){
			for(int j = 0; j < 4; j++){
				 botones[i][j] = gtk_button_new_with_label ("----");
			}
		}

    for(int i = 1; i < 6 ; i++){
			for(int j = 0; j < 4; j++){
				 GtkWidget* button =botones[i][j];  
                gtk_grid_attach (GTK_GRID(grid), button, i,j,1,1);;
			}
		}
  */
    for(int i = 0;  i < 4; i++){
        for(int j = 1; j < 100; j++){
            //GtkWidget* label = gtk_label_new ("Vemos");
            GtkWidget* label = gtk_button_new_with_label ("Vemos");
            gtk_grid_attach (GTK_GRID(grid), label, i,j,1,1);
            gtk_widget_show_all (label);

        }
    }

			
		
}

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    pausadaStarted = 0;


    gtk_init(&argc, &argv);

    // builder = gtk_builder_new();
    // gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    // Update October 2019: The line below replaces the 2 lines above
    builder = gtk_builder_new_from_file("glade/mainWindow.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));
    GdkColor color;
    gdk_color_parse ("#E8F8F5", &color);

    gtk_widget_modify_bg ( GTK_WIDGET(window), GTK_STATE_NORMAL, &color);

    GtkContainer *Grid = GTK_CONTAINER(gtk_builder_get_object(builder, "bitacora_grid"));

    continua_radio =  GTK_WIDGET(gtk_builder_get_object(builder, "continua_radio"));
    pausada_radio =  GTK_WIDGET(gtk_builder_get_object(builder, "pausada_radio"));
    
    rastrear_button =  GTK_WIDGET(gtk_builder_get_object(builder, "rastrear_button"));
    next_button =  GTK_WIDGET(gtk_builder_get_object(builder, "next_button"));
    
    desplegarMarik(Grid);

    gtk_widget_set_sensitive (next_button, FALSE);
    gtk_builder_connect_signals(builder, NULL);
	
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}






// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}