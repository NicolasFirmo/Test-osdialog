#include <gtk/gtk.h>
#include <osdialog.h>
#include <iostream>

static void
activate(GtkApplication *app,
         gpointer user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Hello GNOME");
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
  gtk_widget_show_all(window);
}

int main(int argc, char *argv[])
{
  // GtkApplication *app;
  int status;

  // app = gtk_application_new("org.gtk.example",
  //                           G_APPLICATION_FLAGS_NONE);
  // g_signal_connect(app, "activate",
  //                  G_CALLBACK(activate), NULL);
  // status = g_application_run(G_APPLICATION(app), argc, argv);
  // g_object_unref(app);

  // auto file = osdialog_file(OSDIALOG_OPEN, NULL, NULL, NULL);
  // std::cout << file << '\n';

  osdialog_color color0 = {200, 200, 100};
  std::cout << "cor antes: "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 0) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 1) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 2) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 3)
            << '\n';
  osdialog_color_picker(&color0, 0);
  std::cout << "cor depois: "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 0) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 1) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 2) << ", "
            << (int)*((uint8_t *)(&color0) + sizeof(uint8_t) * 3)
            << '\n';

  return (status);
}
