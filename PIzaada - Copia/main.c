#include <allegro.h>
#include <time.h>

void pause();

int width = 800, height = 600, pausa = 0;

int main(){

    //Inicialização
    allegro_init();
    install_mouse();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);


    set_window_title("Crowd is NOT an Option!");

    //Variáveis
    int xboneco, yboneco, mortes = 0, xboneco2, pausa = 0;
    float x= 10, y = 10, xcorona = 0, xcoronaVerde = 0, ycorona = 400 , hori = 0.25, horiVerde = 0.5, posicorona, posicoronaY = 200, sec=0, min=0, i=0;
    
    //Bitmaps
    BITMAP* buffer = create_bitmap(800, 600);
    BITMAP* fundo = load_bitmap("fundo.bmp",NULL);
    BITMAP* face = load_bitmap("face.bmp",NULL);
    BITMAP* direita = load_bitmap("direita.bmp",NULL);
    BITMAP* esquerda = load_bitmap("esquerda.bmp",NULL);
    BITMAP* costas = load_bitmap("costas.bmp",NULL);
    BITMAP* fbackup = load_bitmap("face.bmp",NULL);
    BITMAP* corona = load_bitmap("corona.bmp",NULL);
    BITMAP* coronaazul = load_bitmap("coronaazul.bmp",NULL);
    BITMAP* coronaverde = load_bitmap("coronaverde.bmp",NULL);
    BITMAP* mouse = load_bitmap("mouse.bmp",NULL);
    BITMAP* gameover = load_bitmap("demora.bmp",NULL);
    
 
  	
    //inicio
	while(!key[KEY_ESC] && min != 60){
		
		//Pausa
		if(key[KEY_ENTER] && !pausa){
		
		pausa = 1;
		textprintf_centre_ex(buffer, font, 50, 50, makecol(0,0,0), -1, "PAUSADO" );
		
		}
		
		
		xboneco = x + 510; 
		yboneco = y + 561; 
		xboneco2 = xboneco - 200;
		posicorona = xcorona + 400;
		posicoronaY = xcorona + 200 ;
		
	
		if(y == -519)
			break;
		
		//movimento corona azul e roxo
		xcorona += hori;
		
			if(xcorona == 270)
				hori *= -1;			
			
			if(xcorona == -105)
				hori *= -1;	
				
		//movimento corona verde
		xcoronaVerde += horiVerde;
		
			if(xcoronaVerde == 270)
				horiVerde *= -1;
				
			if(xcoronaVerde == -105)
				horiVerde *=  -1;
		
		//X	
		if(xboneco == posicorona + 5 && y < -104 && y > -155){
			x = 160;
			y = 10 ;
		}
	
		if(xboneco == posicorona + 5 && y < -405 && y > -460){
			x = 160;
			y = 10 ;
		}
		
		//Y
		
		if(xboneco2 == posicoronaY && xboneco < 606 && xboneco > 655){
			x = 160;
			y = 10 ;
		}
		if(xboneco2 == posicoronaY && xboneco < 400 && xboneco > 450){
			x = 160;
			y = 10 ;
		}
		
		
	
			//andar boneco
			if(key[KEY_RIGHT] && x < 194 ){
	        x += 0.125;
	        face = direita;
	        }
	
	        if(key[KEY_LEFT] && x > -205 ){  
	        x -= 0.125;
	        face = esquerda;
	
	        }
	
	        if(key[KEY_UP] && y > -520){
	        y -= 0.125;
	        face = costas ;
	
	        }
	
	        if(key[KEY_DOWN] && y < 10){
	        y += 0.125;
	        face = fbackup;
	        }
			
			
			//cronometro		
			if(sec==1000){
				sec=0;
				min++;
			}
			sec++;
		
		//desenha as sprites
		draw_sprite(buffer, fundo, 0,0);
		textprintf_ex(buffer, font, 100, 100, makecol(0,0,0), -1, "%.1fseg %.1fmilisegundo", min, sec);	
		textprintf_ex(buffer, font, 200, 260, makecol(0,0,0), -1, "mx %i my %i  xboneco %i  yboneco %i xcorona %.2f ycorona %f  ",mouse_x, mouse_y, xboneco2, yboneco,posicorona, posicoronaY);
		draw_sprite(buffer, mouse, mouse_x, mouse_y);
		draw_sprite(buffer, corona, 400 + xcorona , 400);
		draw_sprite(buffer, coronaazul, 400  , 200 + xcorona);
		draw_sprite(buffer, coronaverde, 400 + xcoronaVerde , 200 + xcoronaVerde);
		draw_sprite(buffer, coronaazul, 600 , 200 + xcorona);
		draw_sprite(buffer, corona, 400 + xcorona , 100);
       	draw_sprite(buffer, face, 490 + x, 530 + y);
  		draw_sprite(screen, buffer, 0, 0);
  		draw_sprite(buffer, gameover, 0,0);	
  		pause();
        clear(buffer);

    }
    
    while(!key[KEY_ESC]){
	  	draw_sprite(screen, buffer, 0, 0);
  		draw_sprite(buffer, gameover, 0,0);	
	}

	//destroi tudo quando acaba
    destroy_bitmap(buffer);
    destroy_bitmap(fundo);
    destroy_bitmap(face);
    destroy_bitmap(direita);
    destroy_bitmap(esquerda);
    destroy_bitmap(costas);
    destroy_bitmap(corona);
    destroy_bitmap(mouse);
    destroy_bitmap(coronaverde);
	destroy_bitmap(coronaazul);
	destroy_bitmap(gameover);
    
    
    return 0;
}
END_OF_MAIN();

//função de pausa
void pause(){
	
	while(key[KEY_ENTER] && pausa );
	while(!key[KEY_ENTER] && pausa );
	pausa = 0;
	while( key[KEY_ENTER] && !pausa);
	
	}
