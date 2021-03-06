//http://www.stack.nl/~dimitri/doxygen/manual/commands.html#cmdsection
/**
 * @file   character.h
 * @author Thales Lima Menezes
 * @date   08/11/2017
 * @brief  Contém todas as definições, informações e funções
 * relacionadas com os personagens e suas interações.
 */

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "lista_dupla.h"

typedef struct {
	char* name;
	char* house;
	int agility;
	int strength;
	int intelligence;
	int health;
} Character;

typedef struct {
	Character* character;
	int nerf;
	int buff;
} Steroids;

typedef struct node{
	Character* character;
	struct node* left;
	struct node* right;
} t_node;

#include "arvore.h"

Character* character_create   (char* _name, char* _house, int _agility,
int _strength, int _intelligence, int _health);

var_lista* loadFromFile       (char* src_personagens);

void       loadFighters       (t_node* torneio, var_lista* personagens_jogaveis);

void       character_free     (Character* character);

void       free_listaCharacter(var_lista* lista);

Character* fight              (Character* fighter_one, Character* fighter_two,
int atribute);

bool       esta_vivo          (Character* users_choice, var_lista* torneio_status);

Steroids*  aloca_steroids     (void);

void       insere_steroids    (var_lista* lista, Character* character,
int nerf, int buff);

void       print_character    (Character* character, int print_code,
var_lista* steroids);

#endif

/**
 * @struct node
 * @var node::character ponteiro para variável do
 * tipo Character que armazena toda a ficha de um
 * personagem.
 * @var node::left ponteiro para o nó à esquerda
 * do nó atual dentro da árvore.
 * @var node::right ponteiro para o nó à direita
 * do nó atual dentro da árvore.
 */
