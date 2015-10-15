//window.h

#include <stdlib.h>
#include <gtk/gtk.h>
#include"../ImageProcessing/startProcessing.h"
#include"../NeuralSystem/executeSystem.h"
#include"../Helper/mathsHelper.h"

#ifndef WINDOW_H
#define WINDOW_H

int launchWindow(int argc, char* argv[]);
void OnQuit(gpointer data);
void OnAbout(gpointer data, guint callback_action,GtkWidget *widget);
void OnOpen();
void OnLaunch();
void file_selection();
void getPath(GtkWidget *file_selection);

#endif