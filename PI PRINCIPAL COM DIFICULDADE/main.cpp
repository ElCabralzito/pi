#include <allegro.h>


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
    BITMAP* coronaverde = load_bitmap("coronaverde.bmp",NULL);
    BITMAP* mouse = load_bitmap("mouse.bmp",NULL);
    BITMAP* fundo2 = load_bitmap("fundo2.bmp",NULL);
    BITMAP* fundomenu = load_bitmap("fundomenu.bmp",NULL);
    BITMAP* dificuldade = load_bitmap("facil.bmp",NULL);
    BITMAP* facil = load_bitmap("facil.bmp",NULL);
    BITMAP* dificil = load_bitmap("medio.bmp",NULL);
    BITMAP* gameover = load_bitmap("desistiu.bmp",NULL);
    BITMAP* desistiuu = load_bitmap("gameover.bmp",NULL);
    SAMPLE* musica = load_wav("musica2.wav");
    SAMPLE *passo1 = load_wav("stepdirt_1.wav");
  	play_sample(musica, 40,128, 1000,1);
  	
    
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
	int i = 5;
	
	//inicio
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
    	
    //WHILE 2
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
	destroy_sample(musica);
	destroy_sample(passo1);
	destroy_bitmap(fundo2);
    
    
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


	
