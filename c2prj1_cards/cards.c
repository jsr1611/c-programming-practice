#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value >= 2) && (c.value <= 14));
  assert((c.suit >= SPADES) &&  (c.suit <= CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; 
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; 
  case FULL_HOUSE: return "FULL_HOUSE"; 
  case FLUSH: return "FLUSH"; 
  case STRAIGHT: return "STRAIGHT"; 
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; 
  case TWO_PAIR: return "TWO_PAIR"; 
  case PAIR: return "PAIR"; 
  default : return "NOTHING"; 
  }
}

char value_letter(card_t c) {
  if(c.value >= 2 && c.value <=9) {return c.value+50;}
  else{
  switch(c.value){
  case 10: return 48;
  case 11: return 74; 
  case 12: return 81; 
  case 13: return 75; 
  case 14: return 65; 
  default: return 63; 
  }
  }
}

char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES:    return 's';    
  case HEARTS:    return 'h';    
  case DIAMONDS:  return 'd';    
  case CLUBS:     return 'c'; 
  default: return '?';
  }
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));  
}
card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case '2': temp.value = 2; break;
  case '3': temp.value = 3; break;
  case '4': temp.value = 4; break;
  case '5': temp.value = 5; break;
  case '6': temp.value = 6; break;
  case '7': temp.value = 7; break;
  case '8': temp.value = 8; break;
  case '9': temp.value = 9; break;
  case '0': temp.value = 10; break;
  case 'J': temp.value = VALUE_JACK; break;
  case 'Q': temp.value = VALUE_QUEEN; break;
  case 'K': temp.value = VALUE_KING; break;
  case 'A': temp.value = VALUE_ACE; break;        
  }
  switch(suit_let){
  case 's': temp.suit = SPADES; break;
  case 'h': temp.suit = HEARTS; break;
  case 'd': temp.suit = DIAMONDS; break;
  case 'c': temp.suit = CLUBS; break;    
  }
    assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;

  if(c>=0 && c<4){  temp.value = '2'; }
  if(c>=4 && c<8){  temp.value = '3';}
  if(c>=8 && c<12){  temp.value = '4'; }
  if(c>=12 && c<16){ temp.value = '5';}
  if(c>=16 && c<20){ temp.value = '6'; }
  if(c>=20 && c<24){  temp.value = '7';}
  if(c>=24 && c<28){ temp.value = '8'; }
  if(c>=28 && c<32){ temp.value = '9';}
  if(c>=32 && c<36){ temp.value = '0';}
  if(c>=36 && c<40){ temp.value = 'J'; }
  if(c>=40 && c<44){ temp.value = 'Q';}
  if(c>=44 && c<48){ temp.value = 'K'; }
  if(c>=48 && c<52){ temp.value = 'A';}
    
    
  if (c==0 || c==4 || c==8 || c==12 || c==16 || c==20 || c == 24 || c==28 || c==32 || c==36 || c==40 || c==44 || c==48){
    temp.suit = 's';
  }
  if (c==1 || c==5 || c==9 || c==13 || c==17 || c==21 || c == 25 || c==29 || c==33 || c==37 || c==41 || c==45 || c==49){
    temp.suit = 'h';
  }
  if (c==2 || c==6 || c==10 || c==14 || c==18 || c==22 || c == 26 || c==30 || c==34 || c==38 || c==42 || c==46 || c==50){
    temp.suit = 'd';
  }
  if (c==3 || c==7 || c==11 || c==15 || c==19 || c==23 || c == 27 || c==31 || c==35 || c==39 || c==43 || c==47 || c==51){
    temp.suit = 'c';
     } 
    return temp;
}
