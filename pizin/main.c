#include <allegro.h>







int main(){

    //Inicialização
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);

    set_window_title("Teste");

    //Variáveis
    int x= 50, y = 50, fbackup, parkbackup, fundobackup, vidabackup, vida;
    BITMAP* buffer = create_bitmap(800, 600);
    BITMAP* face = load_bitmap("face.bmp",NULL);
    BITMAP* direita = load_bitmap("direita.bmp",NULL);
    BITMAP* esquerda = load_bitmap("esquerda.bmp",NULL);
    BITMAP* costas = load_bitmap("costas.bmp",NULL);
    BITMAP* fundo = load_bitmap("praia.bmp",NULL);
    BITMAP* park = load_bitmap("faker.bmp",NULL);
    BITMAP* logo = load_bitmap ("menu.bmp", NULL);
    BITMAP* tay = load_bitmap ("tay.bmp", NULL);
    BITMAP* jesus = load_bitmap ("jsusu.bmp", NULL);
    BITMAP* vida5 = load_bitmap("image5.bmp",NULL);
    BITMAP* vida4 = load_bitmap("image4.bmp",NULL);
    BITMAP* vida3 = load_bitmap("image3.bmp",NULL);
    BITMAP* vida2 = load_bitmap("image2.bmp",NULL);
    BITMAP* vida1 = load_bitmap("image1.bmp",NULL);
    BITMAP* vida0 = load_bitmap("image0.bmp",NULL);
    BITMAP* corona = load_bitmap("corona.bmp",NULL);
    
    //sons
    SAMPLE *passoUm = load_sample("step1.flac");
    MIDI *somFundo = load_midi("musica.mp3");
    
    play_midi(somFundo, TRUE);
    
    vida = vida5;
	vidabackup = vida;
    fbackup = face;
    parkbackup = park;
    fundobackup = fundo;
	
	
	
    while(!key[KEY_ESC]){
		
		if(x == -60){ //cheia
			vida = vidabackup;
		}
		
		if(x == 100){
			vida = vida4;
		}
		if(x == 200){
			vida = vida3;
		}
		if(x == 300){
			vida = vida2;
		}
		if(x == 400){
			vida = vida1;
		}
		if(x == 500){
			vida = vida0;
		}
		
		//andar
        if(key[KEY_RIGHT] && x < 650 ){
        x += 1;
        face = direita;
        }

        if(key[KEY_LEFT] && x > -60 ){  
        x -= 1;
        face = esquerda;

        }

        if(key[KEY_UP] && y > -330){
        y -= 1;
        face = costas ;

        }

        if(key[KEY_DOWN] && y < 130){
        y += 1;
        face = fbackup;
        }
        //fim andar
        
       
		
        
		
		/*
       if(x == 650){
            fundo = park;
            x = -55;
            y = 0;
            x +=1;
 
        }
        
        if (x == -60){
            fundo = tay;
            x = 645;
            y = 0;
            x +=1;
  
        	
		}
		
		if (y == -330){
			fundo = jesus;
			x = 260;
			y = 100;
            x -=1;
            x +=1;
        	
		}
		
		if (y == 130){
			fundo = fundobackup;
			x = 260;
			y = -320;
            x -=1;
            x +=1;
        
		}
    	*/
		
        draw_sprite(buffer, fundo, 0,0);
		draw_sprite(buffer, vida, 10 , 10);
		draw_sprite(buffer, corona, 600 , 400);
        draw_sprite(buffer, face, 50 + x, 300 + y);
        draw_sprite(screen, buffer, 0, 0);
       

        clear(buffer);


    }

		
    destroy_bitmap(fundo);
    destroy_bitmap(buffer);
    destroy_bitmap(face);
    destroy_bitmap(direita);
    destroy_bitmap(esquerda);
    destroy_bitmap(costas);
    destroy_bitmap(park);
    destroy_bitmap(jesus);
    destroy_bitmap(tay);
    destroy_sample(passoUm);
    destroy_midi(somFundo);	
	destroy_bitmap(vida5);
	destroy_bitmap(vida4);	
	destroy_bitmap(vida3);	
	destroy_bitmap(vida2);	
	destroy_bitmap(vida1);
	destroy_bitmap(vida0);
	destroy_bitmap(corona);
    return 0;
}
END_OF_MAIN();
