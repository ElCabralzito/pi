#include <allegro.h>

int main(){

    //Inicialização
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);

    set_window_title("Crowd is NOT an Option!");

    //Variáveis
    int x= 50, y = 50, fbackup, parkbackup, fundobackup, vidabackup, vida, facilbackup, dificuldade;
    float xm = 0, ym = 0 , hori = 0.25, verti = 0.25;
    
    //Bitmaps
    BITMAP* buffer = create_bitmap(800, 600);
    BITMAP* face = load_bitmap("face.bmp",NULL);
    BITMAP* direita = load_bitmap("direita.bmp",NULL);
    BITMAP* esquerda = load_bitmap("esquerda.bmp",NULL);
    BITMAP* costas = load_bitmap("costas.bmp",NULL);
    BITMAP* fundo = load_bitmap("praia.bmp",NULL);
    BITMAP* vida5 = load_bitmap("image5.bmp",NULL);
    BITMAP* vida4 = load_bitmap("image4.bmp",NULL);
    BITMAP* vida3 = load_bitmap("image3.bmp",NULL);
    BITMAP* vida2 = load_bitmap("image2.bmp",NULL);
    BITMAP* vida1 = load_bitmap("image1.bmp",NULL);
    BITMAP* vida0 = load_bitmap("image0.bmp",NULL);
    BITMAP* corona = load_bitmap("corona.bmp",NULL);
    BITMAP* facil = load_bitmap("facil.bmp",NULL);
    BITMAP* dificil = load_bitmap("medio.bmp",NULL);
    BITMAP* gameover = load_bitmap("gameover.bmp",NULL);
	BITMAP* fundomenu = load_bitmap("fundomenu.bmp",NULL);
	
	//sons
	SAMPLE *musica = load_wav("porrada.wav");
    
    
    //backups de variáveis
    
    int troca = 0;
    
    //inicio
	while(!key[KEY_SPACE]){

	
		//CODIGO PRA BATER NA PAREDE E VOLTAR
		
		xm += hori;
		ym += verti;
		
			if(xm == 500){
				hori *= -1;			
			}
			
			if(xm == -180){
				hori *= -1;			
			}
			
			if(ym == 300){
				verti *= -1;
			}
			
			if(ym == -150){
				verti *= -1;
			} 

		
		draw_sprite(buffer, fundomenu, 0,0);
		draw_sprite(screen, buffer, 0, 0);
		
	  clear(buffer);
	}
	
	//dificuldade
	while(!key[KEY_ENTER]){
		
		if(key[KEY_DOWN]){
			dificuldade = dificil;
			
		}
		if(key[KEY_UP]){
			dificuldade = facil;
			
		}
		draw_sprite(buffer, dificuldade, 0,0);
		draw_sprite(screen, buffer, 0, 0);
		
		 clear(buffer);
	}
	
	//Jogo
    while(vida != vida0){
		
		//treco da barra de vida
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
		
		//desenha as sprites
		
		draw_sprite(buffer, fundo, 0,0);
		draw_sprite(buffer, vida, 10 , 10);
		draw_sprite(buffer, corona, 600 , 400);
        draw_sprite(buffer, face, 50 + x, 300 + y);
        draw_sprite(screen, buffer, 0, 0);
       

        clear(buffer);


    }
    while(!key[KEY_ESC]){
		
		play_sample(porrada, 30,128, 1000,0);
		draw_sprite(buffer, gameover, 0,0);
		draw_sprite(screen, buffer, 0, 0);
		
		 clear(buffer);
	}

		//destroi tudo quando acaba
    destroy_bitmap(fundo);
    destroy_bitmap(buffer);
    destroy_bitmap(face);
    destroy_bitmap(direita);
    destroy_bitmap(esquerda);
    destroy_bitmap(costas);
	destroy_bitmap(vida5);
	destroy_bitmap(vida4);	
	destroy_bitmap(vida3);	
	destroy_bitmap(vida2);	
	destroy_bitmap(vida1);
	destroy_bitmap(vida0);
	destroy_bitmap(corona);
	destroy_bitmap(facil);
	destroy_bitmap(dificil);
	destroy_bitmap(gameover);
	destroy_bitmap(fundomenu);
	destroy_sample(musica);
    return 0;
}
END_OF_MAIN();
