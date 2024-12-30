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
            linked_list_size++;
            Node* new_node = createNode();
            Node* cur_node = head_node;

            if (cur_node == nullptr)
            {
                head_node = new_node;
                static_cast<DoubleNode*>(new_node)->previous = nullptr;
                initializeNode(new_node, nullptr, Operation::TAIL);
                return;
            }

            while (cur_node->next != nullptr)
            {
                cur_node = cur_node->next;
            }

            cur_node->next = new_node;
            static_cast<DoubleNode*>(new_node)->previous = cur_node;
            initializeNode(new_node, cur_node, Operation::TAIL);
        }

        void DoubleLinkedList::insertNodeAtHead()
        {
            linked_list_size++;
            Node* new_node = createNode();

            if (head_node == nullptr)
            {
                head_node = new_node;
                static_cast<DoubleNode*>(new_node)->previous = nullptr;
                initializeNode(new_node, nullptr, Operation::HEAD);
                return;
            }

            initializeNode(new_node, head_node, Operation::HEAD);

            new_node->next = head_node;
            static_cast<DoubleNode*>(head_node)->previous = new_node;
            
            head_node = new_node;
        }

        void DoubleLinkedList::insertNodeAtMiddle()
        {
            if (head_node == nullptr)
            {
                insertNodeAtHead();
                return;
            }

            int midIndex = findMiddleNode();
            insertNodeAtIndex(midIndex);
        }

        void DoubleLinkedList::insertNodeAtIndex(int index)
        {
            if (index < 0 || index >= linked_list_size)return;

            if (index == 0)
            {
                insertNodeAtHead();
                return;
            }

            Node* new_node = createNode();

            int current_index = 0;
            Node* cur_node = head_node;
            Node* prev_node = nullptr;

            while (cur_node != nullptr && current_index < index)
            {
                prev_node = cur_node;
                cur_node = cur_node->next;
                current_index++;
            }

            prev_node->next = new_node;
            static_cast<DoubleNode*>(new_node)->previous = prev_node;
            new_node->next = cur_node;
            static_cast<DoubleNode*>(cur_node)->previous = new_node;
            initializeNode(new_node, prev_node, Operation::TAIL);
            linked_list_size++;
            shiftNodesAfterInsertion(new_node, cur_node, prev_node);
        }

        void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
        {
            Node* next_node = cur_node;
            cur_node = new_node;
            
            while (cur_node != nullptr && next_node != nullptr)
            {
                cur_node->body_part.setPosition(next_node->body_part.getPosition());
                cur_node->body_part.setDirection(next_node->body_part.getDirection());

                prev_node = cur_node;
                cur_node = next_node;
                next_node = next_node->next;
            }

            initializeNode(cur_node, prev_node, Operation::TAIL);
        }

        void DoubleLinkedList::removeNodeAtTail()
        {
            if (head_node == nullptr)return;

            linked_list_size--;

            Node* cur_node = head_node;

            if (cur_node->next == nullptr)
            {
                removeNodeAtHead();
                return;
            }

            while (cur_node->next != nullptr)
            {
                cur_node = cur_node->next;
            }

            Node* previous = static_cast<DoubleNode*>(cur_node)->previous;
            previous->next = nullptr;
            delete(cur_node);
        }

        void DoubleLinkedList::removeNodeAtHead()
        {
            linked_list_size--;

            Node* cur_node = head_node;
            head_node = head_node->next;

            if (head_node != nullptr)
            {
                static_cast<DoubleNode*>(head_node)->previous = nullptr;
            }

            cur_node->next = nullptr;
            delete cur_node;
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