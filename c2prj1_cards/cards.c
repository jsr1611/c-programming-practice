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
  //  assert(value_let);
  // assert(suit_let);
  switch(value_let){
  case 'A':    temp.value = VALUE_ACE;    break;
  case 'K':    temp.value = VALUE_KING;   break;
  case 'Q':    temp.value = VALUE_QUEEN;  break;
  case 'J':    temp.value = VALUE_JACK;   break;
  }
  switch(suit_let){
  case 's':    temp.suit = SPADES;  break;
  case 'h':    temp.suit = HEARTS;  break;
  case 'd':    temp.suit = DIAMONDS;  break;
  case 'c':    temp.suit = CLUBS;  break;        
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c;
  //  assert_card_valid(temp);
  
  if (c>=0 && c<13){     temp.suit = SPADES;  }
  else if (c>=13 && c<26){    temp.suit = HEARTS;      }
  else if(c>=26 && c<39){    temp.suit = DIAMONDS;  }
  else if(c>=32 && c<52)    {      temp.suit = CLUBS;    }
   assert_card_valid(temp);
   return temp;
}
