//@author: Natalya Arsentyeva


#pragma once
#include "../NodeTree/NodeTree.h"

template <typename T>
class AVLTree: public TreeNode<T>
{
private: 
	short balanceFactor; 

	// »спользуютс€ методами класса и избегают "перевешивани€" узлов
	AVLTree<T>* & Left();
	AVLTree<T>* & Right();

public:
	// конструктор
	AVLTree(const T& item, AVLTree<T>* lptr = nullptr, AVLTree<T>* rptr = nullptr, signed short balanceFactor = 0);

	// ћетод доступа к значению фактора баланса
	short get_balanceFactor() const;
	// 
	//
	AVLTree<T> *Left() const;
	AVLTree<T> *Right() const;
};


// 
template <typename T>
short AVLTree<T>::get_balanceFactor() const 
{
	return balanceFactor;
}

//  онструктор
//template <typename T>
//AVLTree<T>::AVLTree<T>(const T& item, AVLTree<T>* lptr = nullptr, AVLTree<T>* rptr = nullptr, signed short balanceFactor = 0) 
//{
//
//}


//
template <typename T>
AVLTree<T>* AVLTree<T>::Left() const 
{
	//AVLTree<T>* pivot = root->Right();
	//AVLTree<T>* tmp = pivot->Left();
	//pivot->setLeft(root);
	//root->setRight(tmp);
}
/*
      root                                pivot
       / \           Left Rotation        / \
      A  pivot      ------------->      root  C
         / \                            / \
       tmp  C                          A   tmp
*/ 


//
template <typename T>
AVLTree<T>* AVLTree<T>::Right() const
{
	//AVLTree<T> * pivot = root->Left();
	//AVLTree<T>* tmp = pivot->Right();
	//pivot->setRight(root);
	//root->setLeft(tmp);
}
/*
       root                           pivot
       / \      Right Rotation        / \
   pivot  C     -------------->      A  root
     / \                                / \
    A   tmp                           tmp  C
*/



// Ќахождение высоты
template <typename T>
int FindHeight(TreeNode<T>* root)
{
    int h = -1;
   
    return h;
}