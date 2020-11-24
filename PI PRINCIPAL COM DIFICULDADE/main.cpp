#include <allegro.h>

struct coron {int wx, wy, x, y, w, h;};
struct coron 
			coron1 = {0,0 ,720, 452, 35, 35},	
			coron2 = {0,0 ,505, 530, 35, 35},
			coron3 = {0,0 ,640, 80, 35, 35},
			coron4 = {0,0 ,520, 320, 35, 35},
			coron5 = {0,0 ,520, 190, 35, 35},
			coron6 = {0,0 ,520, 90, 35, 35},
			coron7 = {0,0 ,460, 500, 35, 35},
			coron8 = {0,0 ,330, 25, 35, 35},
			coron9 = {0,0 ,80, 160, 35, 35},
			coron10 = {0,0 ,330, 350, 35, 35},
			coron11 = {0,0 ,80, 500, 35, 35},
			coron12 = {0,0 ,350, 430, 35, 35},
			coron13 = {0,0 ,70, 420, 35, 35},
			coron14 = {0,0 ,330, 90, 35, 35},
			coron15 = {0,0 ,150, 250, 35, 35},
			coron16 = {0,0 ,200, 30, 35, 35};

struct obj {int wx, wy, x, y, w, h;};
struct obj	
		
		obj2 = {0,0 ,500, 500, 30, 38},
		obj1 = {0,0 ,400, 200, 35, 35},
		obj3 = {0,0 ,400, 300, 35, 35},
		obj4 = {0,0 ,400, 100, 35, 35},
		obj5 = {0,0 ,400, 400, 35, 35},
		obj6 = {0,0 ,300, 200, 35, 35},
		obj7 = {0,0 ,650, 200, 35, 35},
		obj8 = {0,0 ,390, 200, 35, 35},
		obj9 = {0,0 ,500, 200, 35, 35};
		
	
		
				
		
//Funções
 	int colidir(struct obj* A, struct obj* B, BITMAP *imgA, BITMAP* imgB);
	void controles();
	int	colidirP3(struct coron* A, struct obj *B, BITMAP* imgA , BITMAP* imgB);

int main(){

    //Inicialização
    allegro_init();
    install_mouse();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);


    set_window_title("Crowd is NOT an Option!");

    //Variáveis
    int xboneco, yboneco, mortes = 0, xboneco2, hori = 5, verti = 5, vertibuff = 10, vertinegativo = 5, velBoneco = 3;
    float x= 10, y = 10 ;
    bool desistiu = false;
    
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
    BITMAP* coronavermelho = load_bitmap("coronavermelho.bmp",NULL);
    BITMAP* coronaverde = load_bitmap("coronaverde.bmp",NULL);
    BITMAP* mouse = load_bitmap("mouse.bmp",NULL);
    BITMAP* fundo2 = load_bitmap("fundo2.bmp",NULL);
    BITMAP* fundomenu = load_bitmap("fundomenu.bmp",NULL);
    BITMAP* dificuldade = load_bitmap("facil.bmp",NULL);
    BITMAP* facil = load_bitmap("facil.bmp",NULL);
    BITMAP* dificil = load_bitmap("medio.bmp",NULL);
    BITMAP* gameover = load_bitmap("desistiu.bmp",NULL);
    BITMAP* desistiuu = load_bitmap("gameover.bmp",NULL);
    BITMAP* fundo3 = load_bitmap("fundo3.bmp",NULL);
    SAMPLE* musica = load_wav("musica2.wav");
    SAMPLE *passo1 = load_wav("stepdirt_1.wav");
  	play_sample(musica, 40,128, 1000,1);
  	int i = 5;
    
    
    
    //MENU START
    while(!key[KEY_SPACE]){

	
		
		draw_sprite(buffer, fundomenu, 0,0);
		draw_sprite(screen, buffer, 0, 0);
		
	  clear(buffer);
	}
	
	//DIFICULDADE
	dificuldade = facil;
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
	
	if(dificuldade == facil){
			hori = 2;
			verti = 2;
			vertibuff = 5 ;
			vertinegativo = 2;
			velBoneco = 1;
	}
	
	
	
	//VIDAS
	
	
	
	//FASE 1
	while(!key[KEY_ESC] && obj2.y != 20 && !key[KEY_O]){
	
			
			if(i==0){
				gameover = desistiuu;
					while(!key[KEY_ESC]){
					
				
					draw_sprite(buffer, gameover, 0,0);
					draw_sprite(screen, buffer, 0, 0);
					
					 clear(buffer);
				}
			}	
			
		//movimento corona
		obj1.x += hori;
			obj3.x += hori;
			obj4.x += hori;
			obj5.x += hori;
			obj6.y += verti;
			obj7.y += verti;
			obj8.y += vertibuff;
			obj8.x += hori;
		
		
		//limite de movimento corona
		if(obj1.x == 680)
			hori *= -1;
		if(obj1.x == 290)
			hori *= -1;
		if(obj6.y == 100)
			verti *= -1;
		if(obj6.y == 470)
			verti *= -1;
		if(obj8.y == 100)
			vertibuff *= -1;
		if(obj8.y == 470)
			vertibuff *= -1;
		if(obj9.y == 100)
			vertinegativo *= -1;
		if(obj9.y == 470)
			vertinegativo *= -1;
		
	
		//andar boneco
			if(key[KEY_RIGHT] && obj2.x != 686 ){
	        obj2.x += velBoneco;
	        face = direita;
	        play_sample(passo1, 30,128, 1000,0);
	        }
	
	        if(key[KEY_LEFT] && obj2.x != 284 ){  
	        obj2.x -= velBoneco;
	        face = esquerda;
	        play_sample(passo1, 30,128, 1000,0);
	        }
	
	        if(key[KEY_UP]){
	        obj2.y -= velBoneco;
	        face = costas ;
	        play_sample(passo1, 30,128, 1000,0);

	        }
	
	        if(key[KEY_DOWN] && obj2.y != 539){
	        obj2.y += velBoneco;
	        face = fbackup;
			play_sample(passo1, 30,128, 1000,0);
	        } 
		
		
		//desenha as sprites
		draw_sprite(buffer, fundo, 0,0);	
		//textprintf_ex(buffer, font, 200, 260, makecol(0,0,0), -1, "mx %i my %i bonecoX %i bonecoY %i coronaX %i coronaY %i",mouse_x, mouse_y, obj2.x, obj2.y, obj1.x, obj1.y);
		textprintf_ex(buffer, font, 290, 555, makecol(0,0,0), -1, "Vidas: %d",i);
		draw_sprite(buffer, mouse, mouse_x, mouse_y);
		
		draw_sprite(buffer, corona, obj1.x , obj1.y);
		draw_sprite(buffer, face, obj2.x, obj2.y);
		draw_sprite(buffer, corona, obj3.x , obj3.y);
		draw_sprite(buffer, corona, obj4.x , obj4.y);
		draw_sprite(buffer, corona, obj5.x , obj5.y);
		draw_sprite(buffer, coronaazul, obj6.x , obj6.y);
		draw_sprite(buffer, coronaazul, obj7.x , obj7.y);
		if(colidir(&obj1, &obj2, face, corona) || colidir(&obj3, &obj2, face, corona) || colidir(&obj4, &obj2, face, corona) || colidir(&obj5, &obj2, face, corona) || colidir(&obj6, &obj2, face, coronaazul) || colidir(&obj7, &obj2, face, coronaazul)){
				obj2.x = 500;
				obj2.y = 500;
				i--;
			}
  		draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
        rest(10);
    }
    
    	obj2.x = 500;
		obj2.y = 500;
		obj3.x = 500;
    	obj3.y = 200;
    
	
	
	//VIDAS	
    i = 5;
    	
    //FASE 2
    while(!key[KEY_ESC] && obj2.y != 20 && !key[KEY_K]){
		
			if(i == 0){
			gameover = desistiuu;
			break;
			}	
			
			
			
		//movimento corona
			obj1.x += hori;
			obj4.x += hori;
			obj5.x += hori;
			obj6.y += verti;
			obj7.y += verti;
			obj8.y += vertibuff;
			obj8.x += hori;
			obj9.y += vertinegativo;
			
		
		//limite de movimento corona
		if(obj1.x == 680)
			hori *= -1;
		if(obj1.x == 290)
			hori *= -1;
		if(obj6.y == 100)
			verti *= -1;
		if(obj6.y == 470)
			verti *= -1;
		if(obj8.y == 100)
			vertibuff *= -1;
		if(obj8.y == 470)
			vertibuff *= -1;
		if(obj9.y == 100)
			vertinegativo *= -1;
		if(obj9.y == 470)
			vertinegativo *= -1;
		
	
		//andar boneco
			if(key[KEY_RIGHT] && obj2.x != 686 ){
	        obj2.x += velBoneco;
	        face = direita;
	        play_sample(passo1, 30,128, 1000,0);
	        }
	
	        if(key[KEY_LEFT] && obj2.x != 284 ){  
	        obj2.x -= velBoneco;
	        face = esquerda;
	        play_sample(passo1, 30,128, 1000,0);
	        }
	
	        if(key[KEY_UP]){
	        obj2.y -= velBoneco;
	        face = costas ;
	        play_sample(passo1, 30,128, 1000,0);

	        }
	
	        if(key[KEY_DOWN] && obj2.y != 539){
	        obj2.y += velBoneco;
	        face = fbackup;
			play_sample(passo1, 30,128, 1000,0);
	        } 
	
		
		//desenha as sprites
		draw_sprite(buffer, fundo2, 0,0);	
		textprintf_ex(buffer, font, 200, 260, makecol(0,0,0), -1, "mx %i my %i bonecoX %i bonecoY %i coronaX %i coronaY %i",mouse_x, mouse_y, obj2.x, obj2.y, obj1.x, obj1.y);

		draw_sprite(buffer, mouse, mouse_x, mouse_y);
		
		draw_sprite(buffer, corona, obj1.x , obj1.y);
		draw_sprite(buffer, face, obj2.x, obj2.y);
		draw_sprite(buffer, corona, obj4.x , obj4.y);
		draw_sprite(buffer, corona, obj5.x , obj5.y);
		draw_sprite(buffer, coronaazul, obj6.x , obj6.y);
		draw_sprite(buffer, coronaazul, obj7.x , obj7.y);
		draw_sprite(buffer, coronaverde, obj8.x , obj8.y);


		if(colidir(&obj1, &obj2, face, corona) || colidir(&obj4, &obj2, face, corona) || colidir(&obj5, &obj2, face, corona) || colidir(&obj6, &obj2, face, coronaazul) || colidir(&obj7, &obj2, face, coronaazul) || colidir(&obj8, &obj2, face, coronaverde)){
				obj2.x = 500;
				obj2.y = 500;
				i--;
			}
  		draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
        rest(10);
	}
	
	
		obj2.x = 720;
		obj2.y = 530;
		i = 10;
	
	
	
//FASE 3	

			
int horicoron1 = 10, verticoron2 = 10, verticoron3 = 10, horicoron4 = 10, horicoron5 = 10 , horicoron6 = 10, horicoron8 = 10, horicoron9 = 10,horicoron10 = 10, horicoron11 = 10, verticoron16 = 10;

	while(!key[KEY_ESC] && !key[KEY_O] && obj2.x ){
	
			
			if(obj2.y >= 35 && obj2.y <= 77 && obj2.x == 54) 
					break;
			
			if(i==0){
				gameover = desistiuu;
					while(!key[KEY_ESC]){
					
				
					draw_sprite(buffer, gameover, 0,0);
					draw_sprite(screen, buffer, 0, 0);
					
					 clear(buffer);
				}
			}	
			
		//movimento corona
			coron1.x += horicoron1;
			coron2.y += verticoron2;
			coron3.y += verticoron3;
			coron4.x += horicoron4;
			coron5.x += horicoron5;
			coron6.x += horicoron6;
			coron8.x += horicoron8;
			coron9.x += horicoron9;
			coron10.x += horicoron10;
			coron11.x += horicoron11;
			coron16.y += verticoron16;
			
		//limite de movimento corona
		if(coron1.x == 740)
			horicoron1 *= -1;
		if(coron1.x == 440)
			horicoron1 *= -1;
			
		if(coron2.y == 20)
			verticoron2 *= -1;
		if(coron2.y == 540)
			verticoron2 *= -1;
			
		if(coron3.y == 20)
			verticoron3 *= -1;
		if(coron3.y == 540)
			verticoron3 *= -1;
		
		if(coron4.x == 740)
			horicoron4 *= -1;
		if(coron4.x == 500)
			horicoron4 *= -1;
			
		if(coron5.x == 740)
			horicoron5 *= -1;
		if(coron5.x == 440)
			horicoron5 *= -1;
			
		if(coron6.x == 740)
			horicoron6 *= -1;
		if(coron6.x == 520)
			horicoron6 *= -1;
			
		if(coron8.x == 60)
			horicoron8 *= -1;
		if(coron8.x == 350)
			horicoron8 *= -1;
			
		if(coron9.x == 60)
			horicoron9 *= -1;
		if(coron9.x == 350)
			horicoron9 *= -1;
			
		if(coron10.x == 60)
			horicoron10 *= -1;
		if(coron10.x == 350)
			horicoron10 *= -1;
			
		if(coron11.x == 60)
			horicoron11 *= -1;
		if(coron11.x == 350)
			horicoron11 *= -1;
			
		if(coron16.y == 30)
			verticoron16 *= -1;
		if(coron16.y == 550)
			verticoron16 *= -1;
		
		
	
		//andar boneco
		
		//RIGHT
		if(obj2.y > 239 && obj2.y < 305 ){
			
			if(key[KEY_RIGHT] && obj2.x != 750 ){
		        obj2.x += velBoneco;
		        face = direita;
		        play_sample(passo1, 30,128, 1000,0);
	        }
		}else{
			if(key[KEY_RIGHT] && obj2.x != 369 && obj2.x != 750  ){
		        obj2.x += velBoneco;
		        face = direita;
		        play_sample(passo1, 30,128, 1000,0);
	        }
			
		}

	        //LEFT
			if(obj2.y >= 239 && obj2.y <= 305){
			        if(key[KEY_LEFT] && obj2.x != 54) {
				        obj2.x -= velBoneco;
				        face = esquerda;
				        play_sample(passo1, 30,128, 1000,0);
			        }
			}else {
				if(key[KEY_LEFT] && obj2.x != 435 && obj2.x != 54 ){
				    obj2.x -= velBoneco;
				    face = esquerda;
				    play_sample(passo1, 30,128, 1000,0);
			    }
			}
			
			
			//UP
			if(	obj2.x <= 429 && obj2.x >= 378){
				if(key[KEY_UP] && obj2.y != 245){
		        obj2.y -= velBoneco;
		        face = costas ;
		        play_sample(passo1, 30,128, 1000,0);
		        }	
			}else{	
				
				if(key[KEY_UP] && obj2.y != 11){
			        obj2.y -= velBoneco;
			        face = costas ;
			        play_sample(passo1, 30,128, 1000,0);
		        }
			}	

	     //DOWN   
		if(obj2.x <= 429 && obj2.x >= 375){
			if(key[KEY_DOWN] && obj2.y != 308){
		        obj2.y += velBoneco;
		        face = fbackup;
				play_sample(passo1, 30,128, 1000,0);
	        } 
		}else{
			if(key[KEY_DOWN] && obj2.y != 539){
		        obj2.y += velBoneco;
		        face = fbackup;
				play_sample(passo1, 30,128, 1000,0);
		        } 
		}	
		
		
		
		//desenha as sprites
		draw_sprite(buffer, fundo3, 0,0);	
		//textprintf_ex(buffer, font, 200, 260, makecol(0,0,0), -1, "mx %i my %i bonecoX %i bonecoY %i coronaX %i coronaY %i",mouse_x, mouse_y, obj2.x, obj2.y, obj1.x, obj1.y);
		textprintf_ex(buffer, font, 290, 555, makecol(0,0,0), -1, "Vidas: %d",i);
		draw_sprite(buffer, mouse, mouse_x, mouse_y);
		draw_sprite(buffer, face, obj2.x, obj2.y);
		draw_sprite(buffer, corona, coron1.x , coron1.y);
		draw_sprite(buffer, coronaazul, coron2.x , coron2.y);
		draw_sprite(buffer, coronaazul, coron3.x , coron3.y);
		draw_sprite(buffer, corona, coron4.x , coron4.y);
		draw_sprite(buffer, corona, coron5.x , coron5.y);
		draw_sprite(buffer, corona, coron6.x , coron6.y);
		draw_sprite(buffer, coronavermelho, coron7.x , coron7.y);
		draw_sprite(buffer, corona, coron8.x , coron8.y);
		draw_sprite(buffer, corona, coron9.x , coron9.y);
		draw_sprite(buffer, corona, coron10.x , coron10.y);
		draw_sprite(buffer, corona, coron11.x , coron11.y);
		draw_sprite(buffer, coronavermelho, coron12.x , coron12.y);
		draw_sprite(buffer, coronavermelho, coron13.x , coron13.y);
		draw_sprite(buffer, coronavermelho, coron14.x , coron14.y);
		draw_sprite(buffer, coronavermelho, coron15.x , coron15.y);
		draw_sprite(buffer, coronaazul, coron16.x , coron16.y);
		
		if (colidirP3(&coron1, &obj2, corona, face) || 
			colidirP3(&coron2, &obj2, coronaazul, face) || 
			colidirP3(&coron3, &obj2, coronaazul, face) || 
			colidirP3(&coron4, &obj2, corona, face) || 
			colidirP3(&coron5, &obj2, corona, face) || 
			colidirP3(&coron6, &obj2, corona, face) ||
			colidirP3(&coron7, &obj2, coronavermelho, face) || 
			colidirP3(&coron8, &obj2, corona, face) || 
			colidirP3(&coron9, &obj2, corona, face) || 
			colidirP3(&coron10, &obj2, corona, face) || 
			colidirP3(&coron11, &obj2, corona, face) || 
			colidirP3(&coron12, &obj2, coronavermelho, face) || 
			colidirP3(&coron13, &obj2, coronavermelho, face) || 
			colidirP3(&coron14, &obj2, coronavermelho, face) || 
			colidirP3(&coron15, &obj2, coronavermelho, face) || 
			colidirP3(&coron16, &obj2, coronaazul, face)){
		
				obj2.x = 720;
				obj2.y = 530;
				i--;
			}
			
			
  		draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
        rest(10);
    }
	
			
		
	//FIM
	while(!key[KEY_ESC]){
		
	
		draw_sprite(buffer, gameover, 0,0);
		draw_sprite(screen, buffer, 0, 0);
		
		 clear(buffer);
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
	destroy_bitmap(coronavermelho);
	destroy_sample(musica);
	destroy_sample(passo1);
	destroy_bitmap(fundo2);
	destroy_bitmap(fundo3);
	destroy_bitmap(fbackup);
	destroy_bitmap(fundomenu);
	destroy_bitmap(dificuldade);
	destroy_bitmap(facil);
	destroy_bitmap(dificil);
	destroy_bitmap(gameover);
	destroy_bitmap(desistiuu);
    
    
    return 0;
}
END_OF_MAIN();

	int	colidir(struct obj* A, struct obj *B, BITMAP* imgA , BITMAP* imgB){
	
	int awx = A-> wx, awy = A-> wy, ax = A-> x, ay = A-> y, aw = A-> w, ah = A-> h;  
	int bwx = B-> wx, bwy = B-> wy, bx = B-> x, by = B-> y, bw = B-> w, bh = B-> h;
	
	if(ax+aw > bx && ax < bx + bw && ay + ah > by && ay < by + bh) {
		
		int cx, cy, cw, ch, iax, iay, ibx, iby, i, j;
		
		if(ax > bx){
			cx = ax;
			cw = bw - (ax-bx);
			iax = 0;
			ibx = bw - cw;
		}else{
			cx  = bx;
			cw  = aw - (bx-ax);
			ibx = 0;
			iax = aw - cw;
		 }
		 	if(ay > by){
				cy  = ay;
				ch  = bh - (ay-by);
				iay = 0;
				iby = bh - ch;
			}else{
				cy  = by;
				ch  = ah - (by-ay);
				iby = 0;
				iay = ah - ch;
		 	}
		 
		 for(i = 0; i < cw; i++){
			for(j = 0; j < ch; j++){
				if(getpixel(imgA, i + awx + iax, j + awy + iay) != 0xff00ff && getpixel(imgB, i + bwx + ibx, j + bwy + iby) != 0xff00ff)
				return 1;
				
			}
			
		 }
				
	}
		
	return 0;
}

int	colidirP3(struct coron* A, struct obj *B, BITMAP* imgA , BITMAP* imgB){
	
	int awx = A-> wx, awy = A-> wy, ax = A-> x, ay = A-> y, aw = A-> w, ah = A-> h;  
	int bwx = B-> wx, bwy = B-> wy, bx = B-> x, by = B-> y, bw = B-> w, bh = B-> h;
	
	if(ax+aw > bx && ax < bx + bw && ay + ah > by && ay < by + bh) {
		
		int cx, cy, cw, ch, iax, iay, ibx, iby, i, j;
		
		if(ax > bx){
			cx = ax;
			cw = bw - (ax-bx);
			iax = 0;
			ibx = bw - cw;
		}else{
			cx  = bx;
			cw  = aw - (bx-ax);
			ibx = 0;
			iax = aw - cw;
		 }
		 	if(ay > by){
				cy  = ay;
				ch  = bh - (ay-by);
				iay = 0;
				iby = bh - ch;
			}else{
				cy  = by;
				ch  = ah - (by-ay);
				iby = 0;
				iay = ah - ch;
		 	}
		 
		 for(i = 0; i < cw; i++){
			for(j = 0; j < ch; j++){
				if(getpixel(imgA, i + awx + iax, j + awy + iay) != 0xff00ff && getpixel(imgB, i + bwx + ibx, j + bwy + iby) != 0xff00ff)
				return 1;
				
			}
			
		 }
				
	}
		
	return 0;
}


	
