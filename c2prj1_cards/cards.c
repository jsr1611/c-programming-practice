#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value == 0) || (c.value >= 2 && c.value <= 14));
  assert((c.suit == SPADES) || (c.suit == HEARTS) || (c.suit == DIAMONDS) || (c.suit == CLUBS));
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
  if(c.value >= 2 && c.value <=9) return c.value+'0';
  else{
  switch(c.value){
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

  /* temp.value = value_let;
  temp.suit = suit_let;
  assert_card_valid(temp);
  */
  temp.value = value_letter(temp);
  temp.suit = suit_letter(temp);
 
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c%13 + 1;
  temp.suit = c%13;
 
   return temp;
}
