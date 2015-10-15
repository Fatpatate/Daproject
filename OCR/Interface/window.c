//window.c

#include"window.h"
#include"../ImageProcessing/learnAndTry.h"


int launchWindow(int argc, char* argv[])
{

	/* Définition of the elements of the menu*/
	GtkItemFactoryEntry MenuItem[] =
	{
		{ "/_File", NULL, NULL, 0, "<Branch>", NULL },
		{ "/File/_Open",NULL,OnOpen, 0, "<StockItem>", GTK_STOCK_OPEN},
		{ "/File/_Save", NULL, NULL, 0, "<StockItem>", GTK_STOCK_SAVE},
		{ "/File/_Close", "<ctrl>S", NULL, 0, "<StockItem>", GTK_STOCK_CLOSE },
		{ "/File/Sep1", NULL, NULL, 0, "<Separator>", NULL },
		{ "/File/_Quit", NULL, OnQuit, 1, "<StockItem>", GTK_STOCK_QUIT},
		{ "/_Edit", NULL,NULL, 0, "<Branch>", NULL},
		{"/_Neural System", NULL, NULL, 0 , "<Branch>", NULL},
		{"/Neural System/Launch", NULL, OnLaunch, 0, "<StockItem>", NULL},
		{ "/_?", NULL, NULL, 0, "<Branch>", NULL},
		{ "/?/_About...", "<CTRL>A", NULL, 1, "<StockItem>", GTK_STOCK_HELP}
	};

	/* Nb of elements*/
	gint iNbMenuItem = sizeof(MenuItem) / sizeof(MenuItem[0]);

	GtkWidget *pWindow;
	GtkWidget *pVBox;
	GtkWidget *pMenuBar;
	GtkItemFactory *pItemFactory;
	GtkAccelGroup *pAccel;

	gtk_init(&argc, &argv);

	/* Creation of the window */
	pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(pWindow), "Rosetta Stone");
	gtk_window_set_default_size(GTK_WINDOW(pWindow), 500, 500);
	g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit),
						 NULL);

	pVBox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(pWindow), pVBox);

	/* Creation of the acceleration table*/
	pAccel = gtk_accel_group_new();

	/* menu creation */
	pItemFactory = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<main>", pAccel);
	/* Take the elements of the menu */
	gtk_item_factory_create_items(pItemFactory, iNbMenuItem, MenuItem,
								 (GtkWidget*)pWindow);
	
	pMenuBar = gtk_item_factory_get_widget(pItemFactory, "<main>");
	/* Top Menu */
	gtk_box_pack_start(GTK_BOX(pVBox), pMenuBar, FALSE, FALSE, 0);
	/* Shortcuts*/
	gtk_window_add_accel_group(GTK_WINDOW(pWindow), pAccel);

	/* Other menu */
	pItemFactory = gtk_item_factory_new(GTK_TYPE_OPTION_MENU, "<main>", NULL);
	
	gtk_item_factory_create_items(pItemFactory, iNbMenuItem, MenuItem,
								 (GtkWidget*)pWindow);
	
	pMenuBar = gtk_item_factory_get_widget(pItemFactory, "<main>");

	gtk_widget_show_all(pWindow);
	gtk_main();

	return EXIT_SUCCESS;
}
void file_selection()
{
	GtkWidget *selection;

	selection = gtk_file_selection_new( g_locale_to_utf8( "Select a file", -1,
									NULL, NULL, NULL) );
	gtk_widget_show(selection);

	//Stop other windows interactions
	gtk_window_set_modal(GTK_WINDOW(selection), TRUE);

	g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(selection)->ok_button),
					"clicked", G_CALLBACK(getPath), selection );

	g_signal_connect_swapped(
						G_OBJECT(GTK_FILE_SELECTION(selection)->cancel_button),
						"clicked", G_CALLBACK(gtk_widget_destroy), selection);
}

void getPath(GtkWidget *file_selection)
{
	const gchar* path;
	GtkWidget *dialog;
	path = gtk_file_selection_get_filename(GTK_FILE_SELECTION (file_selection));

	dialog = gtk_message_dialog_new(GTK_WINDOW(file_selection),
			GTK_DIALOG_MODAL,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK,
			"You have chosen :\n%s", path);

	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	gtk_widget_destroy(file_selection);

	GtkWidget *pWindow;
    GtkWidget *pVBox;
    GtkWidget *pImage;
    GtkWidget *pQuitImage;
    GtkWidget *pQuitBtn;


    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 320, 200);
    gtk_window_set_title(GTK_WINDOW(pWindow), "GtkImage");
    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit),
					NULL);

    pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(pWindow), pVBox);

    //Load image 
    pImage = gtk_image_new_from_file(path);
    gtk_box_pack_start(GTK_BOX(pVBox), pImage, FALSE, FALSE, 5);

    pQuitBtn = gtk_button_new();
    gtk_box_pack_start(GTK_BOX(pVBox), pQuitBtn, TRUE, FALSE, 5);
    g_signal_connect(G_OBJECT(pQuitBtn), "clicked", G_CALLBACK(gtk_main_quit),
					NULL);

  
    pQuitImage = gtk_image_new_from_stock(GTK_STOCK_QUIT,
											GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_container_add(GTK_CONTAINER(pQuitBtn), pQuitImage);

    gtk_widget_show_all(pWindow);
}
void OnQuit(gpointer data)
{
	GtkWidget *pQuestion;

	pQuestion = gtk_message_dialog_new(GTK_WINDOW(data),
			GTK_DIALOG_MODAL,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			"Do you really want to\n"
			"quit the program?");

	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
		case GTK_RESPONSE_YES:
			gtk_main_quit();
			break;
		case GTK_RESPONSE_NONE:
		case GTK_RESPONSE_NO:
			gtk_widget_destroy(pQuestion);
			break;
	}
}

void selectFile()
{
	GtkWidget *dialog;
	dialog = gtk_file_chooser_dialog_new ("Open File",
     				      NULL,
     				      GTK_FILE_CHOOSER_ACTION_OPEN,
     				      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
     				      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
     				      NULL);

     if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
       {
         char *filename;
         filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
		 SDL_Surface *img = load_image(filename);
         startProcessing(img);
         g_free (filename);
       }
     gtk_widget_destroy(dialog);
}

void OnOpen()
{
  selectFile();
}

void OnLaunch()
{
	
	struct NeuralSystem	*lNeuralSystem	= NULL;
	double			InputsXOR[4][3]	=
							{{0.,0.,0.}, {0., 1.,1.}, {1.,0.,1.},{1.,1.,0.}};
	int			lNumberOfLoops	= 10000;

	printf("Initalizing Neural system: Number of loops: %d, Truth Table:XOR.\n",
			lNumberOfLoops);
	lNeuralSystem = neuralSystemInit(lNumberOfLoops, funcXOR, InputsXOR);
	printf("Neural system initialized!\nPress any key to activate it!\n\n\n");

	//wait_for_keypressed();
	
	executeSystem(lNeuralSystem, 4);
	printf("\n\nNeural system has been executed successfully!\n");
	//We can printf precision rate of 4 neurons / 4
	
	//learnAndTry();
}


