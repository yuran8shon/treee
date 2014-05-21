// techimet4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <locale.h>

/** @struct tree
@brief структура дерева
@var info данные.
@var left указатель на левого сына.
@var right указатель на правого сына.
 **/
struct tree {
  char info;
  struct tree *left;
  struct tree *right;
  };

/**
@function stree
@brief добавление нового элемента
@param RR корневой элемент
@param r новый элемент
@param info данные
@return RR корневой элемент с указателем на новый**/
tree *stree(
  tree *RR,
  tree *r,
  char info  
  )
{
  if(!r)/**проверка наличия сына. В случае его отсутствия создается новый,
		в противном случае указатель спускается ниже в соответствии с правилом
		и повторяет данное действие за счет рекурсии **/ {
    r = new tree;
    if(!r) {
      printf("Не хватает памяти\n");
      exit(0);
    }
    r->left = NULL;
    r->right = NULL;
    r->info = info;
    if(!RR)
		{
			
			return r;}/* первый вход */
    if(info < RR->info) 
		{
			RR->left = r;
			
	}

    else 
		{
			RR->right = r;
			
	}
	return r;
  }
  if(info < r->info) 
    stree(r,r->left,info);
  else
    stree(r,r->right,info);

  return RR; 
}

/**
@function inorder
@brief симметрический обход
@param RR дерево
@return функция возвращает пустое значение**/
void inorder(struct tree *RR)
{
  if(!RR) return;

  inorder(RR->left);
  if(RR->info) printf("%c ", RR->info);
  inorder(RR->right);
}


/**
@function preorder
@brief прямой обход
@param RR дерево
@return функция возвращает пустое значение**/
void preorder(struct tree *RR)
{
  if(!RR) return;

  if(RR->info) printf("%c ", RR->info);
  preorder(RR->left);
  preorder(RR->right);
}


/**
@function postorder
@brief обратный обход
@param RR дерево
@return функция возвращает пустое значение**/
void postorder(struct tree *RR)
{
  if(!RR) return;

  postorder(RR->left);
  postorder(RR->right);
  if(RR->info) printf("%c ", RR->info);
}






int _tmain(int argc, _TCHAR* argv[])
{
	setlocale( LC_CTYPE, ".1251" );
	char s[80];
	tree* RR;

	RR = NULL;  /* инициализация корня дерева */

	do {
    printf("Введите букву: ");
    gets(s);
    RR = stree(RR, RR, *s);
  } while(*s);

	std::cout << "Симметричный обход";
	inorder(RR);
	std::cout << std::endl;
	std::cout << "Прямой обход";
	preorder(RR);
	std::cout << std::endl;
	std::cout << "Обратный обход";
	
	postorder(RR);
	std::cout << std::endl;


	return 0;
}

