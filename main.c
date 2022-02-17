#include <gtk/gtk.h>
#include <stdio.h>

GtkBuilder *builder;
GtkWidget *window;
GtkFixed *fixed;
GtkLabel *label1;
int i = 0;

gboolean update();

int main(int argc, char **argv) {
    // Init GTK+
    gtk_init(&argc, &argv);

    // Init the builder
    builder = gtk_builder_new_from_file("DiskIOMonitor.glade");

    // Pointers to GTK Objects
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    fixed = GTK_FIXED(gtk_builder_get_object(builder, "fixed"));
    label1 = GTK_LABEL(gtk_builder_get_object(builder, "label1"));

    // Connect signals
    gtk_builder_connect_signals(builder, NULL);

    // Show window
    gtk_widget_show(window);

    // Set update to run every second
    g_timeout_add_seconds(1, update, NULL);

    // Main loop
    gtk_main();

    return 0;
}

gboolean update() {
	char *buffer;
	buffer = malloc(50 * sizeof(char));
	sprintf(buffer, "%d", i);
    gtk_label_set_text(label1, buffer);
    free(buffer);
    return TRUE;
}
