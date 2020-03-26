#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value >= 2) || (c.value <= 14));
  assert((c.suit == SPADES) || (c.suit == HEARTS) || (c.suit == DIAMONDS) || (c.suit == CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
  // first 3 are flop, 4th = turn, 5th = river
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; break;
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; break;
  case FULL_HOUSE: return "FULL_HOUSE"; break;
  case FLUSH: return "FLUSH"; break;
  case STRAIGHT: return "STRAIGHT"; break;
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; break;
  case TWO_PAIR: return "TWO_PAIR"; break;
  case PAIR: return "PAIR"; break;
  default : return "NOTHING"; break;
  }
}

char value_letter(card_t c) {
  switch(c.value){

 case 2:  return 50;  break;
 case 3:  return 51;  break;
 case 4:  return 52;  break;
 case 5:  return 53;  break;
 case 6:  return 54;  break;
 case 7:  return 55;  break;
 case 8:  return 56;  break;
 case 9:  return 57;  break;
 case 10:  return 48;  break;
 case 11: return 74;  break;
 case 12: return 81;  break;
 case 13: return 75;  break;
 case 14: return 65;  break;   
  default: return 63; break;
 }
}

char suit_letter(card_t c) {
  switch(c.suit){

  case SPADES:    return 's';    break;
  case HEARTS:    return 'h';    break;
  case DIAMONDS:  return 'd';    break;
  case CLUBS:     return 'c';    break;
  default: return '0'; break;
  }
}

void print_card(card_t c) {
  printf("%d%d", value_letter(c), suit_letter(c));  
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  assert(value_let);
  assert(suit_let);
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
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  card_t tmp;

  if (c<13){
    tmp.value = c;
    temp.value = value_letter(tmp);
    temp.suit = SPADES;
  }
  else if (c>=13 || c<26){
    tmp.value = c%13;
    temp.value = value_letter(tmp);
    temp.suit = HEARTS;
      }
  else if(c>=26 || c<39){
    tmp.value = c%13;
    temp.value = value_letter(tmp);
    temp.suit = DIAMONDS;
  }
  else
    {
      tmp.value = c%13;
      temp.value = value_letter(tmp);
      temp.suit = CLUBS;
    }
  
  return temp;
}
