#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

// Widgets
GtkWidget *window,
          *btnCancel,
          *btnSave,
          *spinXSize,
          *spinYSize,
          *chkKeepRatio,
          *chkDithering,
          *chkFullScreen,
          *cbxTexQuality,
          *cbxTexFiltering,
          *cbxHiResTex,
          *spinVRam,
          *chkShowFPS,
          *chkUseFPSLimit,
          *vboxFPSLimit,
          *radFPSLimitAuto,
          *radFPSLimitManual,
          *spinFPSLimit,
          *chkUseFrameSkipping,
          *cbxOffscreen,
          *cbxFBTex,
          *cbxFBAccess,
          *chkMaskDetect,
          *chkOpaquePass,
          *chkAdvancedBlend,
          *chkScanLines,
          *spinScanLinesBlend,
          *chkFastMdec,
          *chk15bitMdec,
          *chkLineMode,
          *chkAntiAlias,
          *chkOGLExtensions,
          *chkScreenSmoothing,
          *chkUseGameFixes,
          *tblGameFixes,
          *chkCfgFix1,
          *chkCfgFix2,
          *chkCfgFix4,
          *chkCfgFix8,
          *chkCfgFix16,
          *chkCfgFix32,
          *chkCfgFix64,
          *chkCfgFix128,
          *chkCfgFix256,
          *chkCfgFix512,
          *chkCfgFix1024,
          *chkCfgFix2048,
          *chkCfgFix4096,
          *chkCfgFix8192,
          *chkCfgFix16384,
          *chkCfgFix32768,
          *chkCfgFix65536,
          *chkCfgFix131072;

// Save values to the config file
void on_btnSave_clicked( GtkObject *object, gpointer user_data ) {
    FILE *out;
    out = fopen( "gpuPeopsMesaGL.cfg", "w+" );
    
    if ( out ) {

        // Computes the 'fixes' bitfield
        int cfgFixes = 0;
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix1      ) ) ) { cfgFixes +=      1; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix2      ) ) ) { cfgFixes +=      2; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix4      ) ) ) { cfgFixes +=      4; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix8      ) ) ) { cfgFixes +=      8; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix16     ) ) ) { cfgFixes +=     16; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix32     ) ) ) { cfgFixes +=     32; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix64     ) ) ) { cfgFixes +=     64; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix128    ) ) ) { cfgFixes +=    128; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix256    ) ) ) { cfgFixes +=    256; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix512    ) ) ) { cfgFixes +=    512; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix1024   ) ) ) { cfgFixes +=   1024; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix2048   ) ) ) { cfgFixes +=   2048; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix4096   ) ) ) { cfgFixes +=   4096; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix8192   ) ) ) { cfgFixes +=   8192; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix16384  ) ) ) { cfgFixes +=  16384; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix32768  ) ) ) { cfgFixes +=  32768; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix65536  ) ) ) { cfgFixes +=  65536; }
        if ( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkCfgFix131072 ) ) ) { cfgFixes += 131072; }

        // Print data to the config file
        fprintf( out, "\nResX             = %i", gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON(   spinXSize           ) ) );
        fprintf( out, "\nResY             = %i", gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON(   spinYSize           ) ) );        
        fprintf( out, "\nKeepRatio        = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkKeepRatio        ) ) );
        fprintf( out, "\nDithering        = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkDithering        ) ) );
        fprintf( out, "\nFullScreen       = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkFullScreen       ) ) );
        fprintf( out, "\nTexQuality       = %i", gtk_combo_box_get_active(         GTK_COMBO_BOX(     cbxTexQuality       ) ) );
        fprintf( out, "\nTexFilter        = %i", gtk_combo_box_get_active(         GTK_COMBO_BOX(     cbxTexFiltering     ) ) );
        fprintf( out, "\nHiResTextures    = %i", gtk_combo_box_get_active(         GTK_COMBO_BOX(     cbxHiResTex         ) ) );
        fprintf( out, "\nVRamSize         = %i", gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON(   spinVRam            ) ) );        
        fprintf( out, "\nShowFPS          = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkShowFPS          ) ) );
        fprintf( out, "\nUseFrameLimit    = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkUseFPSLimit      ) ) );
        fprintf( out, "\nFPSDetection     = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( radFPSLimitAuto     ) ) );
        fprintf( out, "\nFrameRate        = %i", gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON(   spinFPSLimit        ) ) );
        fprintf( out, "\nUseFrameSkip     = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkUseFrameSkipping ) ) );
        fprintf( out, "\nOffscreenDrawing = %i", gtk_combo_box_get_active(         GTK_COMBO_BOX(     cbxOffscreen        ) ) );
        fprintf( out, "\nFrameTextures    = %i", gtk_combo_box_get_active(         GTK_COMBO_BOX(     cbxFBTex            ) ) );
        fprintf( out, "\nFrameAccess      = %i", gtk_combo_box_get_active(         GTK_COMBO_BOX(     cbxFBAccess         ) ) );
        fprintf( out, "\nMaskDetect       = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkMaskDetect       ) ) );
        fprintf( out, "\nOpaquePass       = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkOpaquePass       ) ) );
        fprintf( out, "\nAdvancedBlend    = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkAdvancedBlend    ) ) );
        fprintf( out, "\nScanLines        = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkScanLines        ) ) );
        fprintf( out, "\nScanLinesBlend   = %i", gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON(   spinScanLinesBlend  ) ) );
        fprintf( out, "\nFastMdec         = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkFastMdec         ) ) );
        fprintf( out, "\n15bitMdec        = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chk15bitMdec        ) ) );
        fprintf( out, "\nLineMode         = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkLineMode         ) ) );
        fprintf( out, "\nAntiAlias        = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkAntiAlias        ) ) );
        fprintf( out, "\nOGLExtensions    = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkOGLExtensions    ) ) );
        fprintf( out, "\nScreenSmoothing  = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkScreenSmoothing  ) ) );
        fprintf( out, "\nUseFixes         = %i", gtk_toggle_button_get_active(     GTK_TOGGLE_BUTTON( chkUseGameFixes     ) ) );
        fprintf( out, "\nCfgFixes         = %i", cfgFixes );
        
        fclose( out );
    }

    gtk_main_quit();
}

// Callbacks used to toggle the sensitivity of some parts of the GUI

void on_chkUseGameFixes_toggled( GtkObject *object, gpointer user_data ) {
    gtk_widget_set_sensitive( tblGameFixes, gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkUseGameFixes ) ) );
}

void on_chkUseFPSLimit_toggled( GtkObject *object, gpointer user_data ) {
    gtk_widget_set_sensitive( vboxFPSLimit, gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkUseFPSLimit ) ) );
}

void on_radFPSLimitManual_toggled( GtkObject *object, gpointer user_data ) {
    gtk_widget_set_sensitive( spinFPSLimit, gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( radFPSLimitManual ) ) );
}

void on_chkScanLines_toggled( GtkObject *object, gpointer user_data ) {
    gtk_widget_set_sensitive( spinScanLinesBlend, gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( chkScanLines ) ) );
}

/* Instanciates the GUI
   Reads the config file
   Sets widget states according to the config file
   Connect callbacks to signals */
int main( int argc, char **argv ) {
    GtkBuilder *builder;
    GError *error = NULL;
    FILE *in;
    char *pB, *p;
    int len, val;
    char t[256];

    gtk_init( &argc, &argv );

    builder = gtk_builder_new();

    // Load the glade file
    if ( ! gtk_builder_add_from_file( builder, "cfgPeopsMesaGL.glade", &error ) ) {
        g_warning( "%s", error->message );
        g_free( error );
        return( 1 );
    }

    // Display the About dialog when the emulator ask for it
    if ( argv[1] && strcmp( argv[1], "ABOUT" ) == 0 ) {
        window = GTK_WIDGET( gtk_builder_get_object( builder, "aboutdialog") );
        gtk_signal_connect( GTK_OBJECT( window ), "destroy",  GTK_SIGNAL_FUNC( gtk_main_quit ), NULL);
        gtk_signal_connect( GTK_OBJECT( window ), "response", GTK_SIGNAL_FUNC( gtk_main_quit ), NULL);
        gtk_widget_show( window );
        gtk_main();
        return 0;
    }

    // Get widgets from the glade file
    window              = GTK_WIDGET( gtk_builder_get_object( builder, "dialog1"             ) );
    btnCancel           = GTK_WIDGET( gtk_builder_get_object( builder, "btnCancel"           ) );
    btnSave             = GTK_WIDGET( gtk_builder_get_object( builder, "btnSave"             ) );
    spinXSize           = GTK_WIDGET( gtk_builder_get_object( builder, "spinXSize"           ) );
    spinYSize           = GTK_WIDGET( gtk_builder_get_object( builder, "spinYSize"           ) );
    chkKeepRatio        = GTK_WIDGET( gtk_builder_get_object( builder, "chkKeepRatio"        ) );
    chkDithering        = GTK_WIDGET( gtk_builder_get_object( builder, "chkDithering"        ) );
    chkFullScreen       = GTK_WIDGET( gtk_builder_get_object( builder, "chkFullScreen"       ) );
    cbxTexQuality       = GTK_WIDGET( gtk_builder_get_object( builder, "cbxTexQuality"       ) );
    cbxTexFiltering     = GTK_WIDGET( gtk_builder_get_object( builder, "cbxTexFiltering"     ) );
    cbxHiResTex         = GTK_WIDGET( gtk_builder_get_object( builder, "cbxHiResTex"         ) );
    spinVRam            = GTK_WIDGET( gtk_builder_get_object( builder, "spinVRam"            ) );
    chkShowFPS          = GTK_WIDGET( gtk_builder_get_object( builder, "chkShowFPS"          ) );
    chkUseFPSLimit      = GTK_WIDGET( gtk_builder_get_object( builder, "chkUseFPSLimit"      ) );
    vboxFPSLimit        = GTK_WIDGET( gtk_builder_get_object( builder, "vboxFPSLimit"        ) );
    radFPSLimitAuto     = GTK_WIDGET( gtk_builder_get_object( builder, "radFPSLimitAuto"     ) );
    radFPSLimitManual   = GTK_WIDGET( gtk_builder_get_object( builder, "radFPSLimitManual"   ) );
    spinFPSLimit        = GTK_WIDGET( gtk_builder_get_object( builder, "spinFPSLimit"        ) );
    chkUseFrameSkipping = GTK_WIDGET( gtk_builder_get_object( builder, "chkUseFrameSkipping" ) );
    cbxOffscreen        = GTK_WIDGET( gtk_builder_get_object( builder, "cbxOffscreen"        ) );
    cbxFBTex            = GTK_WIDGET( gtk_builder_get_object( builder, "cbxFBTex"            ) );
    cbxFBAccess         = GTK_WIDGET( gtk_builder_get_object( builder, "cbxFBAccess"         ) );
    chkMaskDetect       = GTK_WIDGET( gtk_builder_get_object( builder, "chkMaskDetect"       ) );
    chkOpaquePass       = GTK_WIDGET( gtk_builder_get_object( builder, "chkOpaquePass"       ) );
    chkAdvancedBlend    = GTK_WIDGET( gtk_builder_get_object( builder, "chkAdvancedBlend"    ) );
    chkScanLines        = GTK_WIDGET( gtk_builder_get_object( builder, "chkScanLines"        ) );
    spinScanLinesBlend  = GTK_WIDGET( gtk_builder_get_object( builder, "spinScanLinesBlend"  ) );
    chkFastMdec         = GTK_WIDGET( gtk_builder_get_object( builder, "chkFastMdec"         ) );
    chk15bitMdec        = GTK_WIDGET( gtk_builder_get_object( builder, "chk15bitMdec"        ) );
    chkLineMode         = GTK_WIDGET( gtk_builder_get_object( builder, "chkLineMode"         ) );
    chkAntiAlias        = GTK_WIDGET( gtk_builder_get_object( builder, "chkAntiAlias"        ) );
    chkOGLExtensions    = GTK_WIDGET( gtk_builder_get_object( builder, "chkOGLExtensions"    ) );
    chkScreenSmoothing  = GTK_WIDGET( gtk_builder_get_object( builder, "chkScreenSmoothing"  ) );
    chkUseGameFixes     = GTK_WIDGET( gtk_builder_get_object( builder, "chkUseGameFixes"     ) );
    tblGameFixes        = GTK_WIDGET( gtk_builder_get_object( builder, "tblGameFixes"        ) );
    chkCfgFix1          = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix1"          ) );
    chkCfgFix2          = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix2"          ) );
    chkCfgFix4          = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix4"          ) );
    chkCfgFix8          = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix8"          ) );
    chkCfgFix16         = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix16"         ) );
    chkCfgFix32         = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix32"         ) );
    chkCfgFix64         = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix64"         ) );
    chkCfgFix128        = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix128"        ) );
    chkCfgFix256        = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix256"        ) );
    chkCfgFix512        = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix512"        ) );
    chkCfgFix1024       = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix1024"       ) );
    chkCfgFix2048       = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix2048"       ) );
    chkCfgFix4096       = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix4096"       ) );
    chkCfgFix8192       = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix8192"       ) );
    chkCfgFix16384      = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix16384"      ) );
    chkCfgFix32768      = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix32768"      ) );
    chkCfgFix65536      = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix65536"      ) );
    chkCfgFix131072     = GTK_WIDGET( gtk_builder_get_object( builder, "chkCfgFix131072"     ) );

    // Read the config file
    in = fopen( "gpuPeopsMesaGL.cfg", "rb" );
    if ( in ) {
        pB = (char *) malloc( 32767 );
        memset( pB, 0, 32767 );
        len = fread( pB, 1, 32767, in );
        fclose(in);
    }
    else pB = 0;

    val = 640;
    if ( pB ) {
        strcpy( t, "\nResX" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_spin_button_set_value( GTK_SPIN_BUTTON( spinXSize ), val );

    val = 480;
    if ( pB ) {
        strcpy( t, "\nResY" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_spin_button_set_value( GTK_SPIN_BUTTON( spinYSize ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nKeepRatio" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkKeepRatio ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nDithering" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkDithering ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nFullScreen" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkFullScreen ), val );
    
    val = 0;
    if ( pB ) {
        strcpy( t, "\nTexQuality" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_combo_box_set_active( GTK_COMBO_BOX( cbxTexQuality ), val );
    
    val = 0;
    if ( pB ) {
        strcpy( t, "\nTexFilter" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_combo_box_set_active( GTK_COMBO_BOX( cbxTexFiltering ), val );
    
    val = 0;
    if ( pB ) {
        strcpy( t, "\nHiResTextures" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_combo_box_set_active( GTK_COMBO_BOX( cbxHiResTex ), val );

    val = 0;
    if ( pB ) {
        strcpy(t,"\nVRamSize");
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_spin_button_set_value( GTK_SPIN_BUTTON( spinVRam ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nShowFPS" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkShowFPS ), val );

    val = 1;
    if ( pB ) {
        strcpy( t, "\nUseFrameLimit" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkUseFPSLimit ), val );

    val = 1;
    if ( pB ) {
        strcpy( t, "\nFPSDetection" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( radFPSLimitAuto ), val );

    val = 60;
    if ( pB ) {
        strcpy(t,"\nFrameRate");
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_spin_button_set_value( GTK_SPIN_BUTTON( spinFPSLimit ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nUseFrameSkip" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkUseFrameSkipping ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nOffscreenDrawing" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_combo_box_set_active( GTK_COMBO_BOX( cbxOffscreen ), val );
    
    val = 0;
    if ( pB ) {
        strcpy( t, "\nFrameTextures" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_combo_box_set_active( GTK_COMBO_BOX( cbxFBTex ), val );
    
    val = 0;
    if ( pB ) {
        strcpy( t, "\nFrameAccess" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_combo_box_set_active( GTK_COMBO_BOX( cbxFBAccess ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nMaskDetect" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkMaskDetect ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nOpaquePass" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkOpaquePass ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nAdvancedBlend" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkAdvancedBlend ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nScanLines" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkScanLines ), val );

    val = 0;
    if ( pB ) {
        strcpy(t,"\nScanLinesBlend");
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_spin_button_set_value( GTK_SPIN_BUTTON( spinScanLinesBlend ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nFastMdec" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkFastMdec ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\n15bitMdec" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chk15bitMdec ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nLineMode" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkLineMode ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nAntiAlias" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkAntiAlias ), val );

    val = 1;
    if ( pB ) {
        strcpy( t, "\nOGLExtensions" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkOGLExtensions ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nScreenSmoothing" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkScreenSmoothing ), val );

    val = 0;
    if ( pB ) {
        strcpy( t, "\nCfgFixes" );
        p = strstr( pB, t );
        if ( p ) {
            p = strstr( p, "=" );
            len = 1;
            val = atoi( p + len );
        }
    }
    if ( val >= 131072 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix131072 ), 131072 ); val -= 131072; }
    if ( val >=  65536 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix65536  ),  65536 ); val -=  65536; }
    if ( val >=  32768 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix32768  ),  32768 ); val -=  32768; }
    if ( val >=  16384 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix16384  ),  16384 ); val -=  16384; }
    if ( val >=   8192 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix8192   ),   8192 ); val -=   8192; }
    if ( val >=   4096 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix4096   ),   4096 ); val -=   4096; }
    if ( val >=   2048 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix2048   ),   2048 ); val -=   2048; }
    if ( val >=   1024 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix1024   ),   1024 ); val -=   1024; }
    if ( val >=    512 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix512    ),    512 ); val -=    512; }
    if ( val >=    256 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix256    ),    256 ); val -=    256; }
    if ( val >=    128 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix128    ),    128 ); val -=    128; }
    if ( val >=     64 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix64     ),     64 ); val -=     64; }
    if ( val >=     32 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix32     ),     32 ); val -=     32; }
    if ( val >=     16 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix16     ),     16 ); val -=     16; }
    if ( val >=      8 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix8      ),      8 ); val -=      8; }
    if ( val >=      4 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix4      ),      4 ); val -=      4; }
    if ( val >=      2 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix2      ),      2 ); val -=      2; }
    if ( val >=      1 ) { gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON( chkCfgFix1      ),      1 ); val -=      1; }

    gtk_builder_connect_signals( builder, NULL );
    
    g_object_unref( G_OBJECT( builder ) );
    
    // Connect callbacks to signals
    gtk_signal_connect( GTK_OBJECT( window ),            "destroy", GTK_SIGNAL_FUNC( gtk_main_quit ),                NULL );
    gtk_signal_connect( GTK_OBJECT( btnCancel ),         "clicked", GTK_SIGNAL_FUNC( gtk_main_quit ),                NULL );
    gtk_signal_connect( GTK_OBJECT( btnSave ),           "clicked", GTK_SIGNAL_FUNC( on_btnSave_clicked ),           NULL );
    gtk_signal_connect( GTK_OBJECT( chkUseGameFixes ),   "toggled", GTK_SIGNAL_FUNC( on_chkUseGameFixes_toggled ),   NULL );
    gtk_signal_connect( GTK_OBJECT( chkUseFPSLimit ),    "toggled", GTK_SIGNAL_FUNC( on_chkUseFPSLimit_toggled ),    NULL );
    gtk_signal_connect( GTK_OBJECT( radFPSLimitManual ), "toggled", GTK_SIGNAL_FUNC( on_radFPSLimitManual_toggled ), NULL );
    gtk_signal_connect( GTK_OBJECT( chkScanLines ),      "toggled", GTK_SIGNAL_FUNC( on_chkScanLines_toggled ),      NULL );

    // Call some callbacks to ensure widget state consistency
    on_chkUseGameFixes_toggled(   GTK_OBJECT( chkUseGameFixes   ), NULL );
    on_chkUseFPSLimit_toggled(    GTK_OBJECT( chkUseFPSLimit    ), NULL );
    on_radFPSLimitManual_toggled( GTK_OBJECT( radFPSLimitManual ), NULL );
    on_chkScanLines_toggled(      GTK_OBJECT( chkScanLines      ), NULL );

    gtk_widget_show( window );

    gtk_main();

    return( 0 );
}

