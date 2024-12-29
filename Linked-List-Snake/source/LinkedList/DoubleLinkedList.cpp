#include"LinkedList/DoubleLinked/DoubleLinkedList.h"
#include"LinkedList/DoubleLinked/DoubleNode.h"
#include"Level/LevelView.h"

namespace LinkedList
{
	namespace DoubleLinked
	{
		DoubleLinkedList::DoubleLinkedList() = default;

		DoubleLinkedList::~DoubleLinkedList() = default;

		Node* DoubleLinkedList::createNode()
		{
			return new DoubleNode();
		}

        void DoubleLinkedList::insertNodeAtTail()
        {

        }

        void DoubleLinkedList::insertNodeAtHead()
        {

        }

        void DoubleLinkedList::insertNodeAtMiddle()
        {

        }

        void DoubleLinkedList::insertNodeAtIndex(int index)
        {

        }

        void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
        {

        }

        void DoubleLinkedList::removeNodeAtTail()
        {

        }

        void DoubleLinkedList::removeNodeAtHead()
        {

        }

        void DoubleLinkedList::removeNodeAtMiddle()
        {

        }

        void DoubleLinkedList::removeNodeAt(int index)
        {

        }

        void DoubleLinkedList::removeNodeAtIndex(int index)
        {

        }

        void DoubleLinkedList::removeAllNodes()
        {

        }

        void DoubleLinkedList::removeHalfNodes()
        {

        }

        void DoubleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
        {

        }

        Direction DoubleLinkedList::reverse()
        {

        }
	}
}