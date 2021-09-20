#include "pch.h"
#include "CppUnitTest.h"
#include "../main/RedBlackTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRBTree
{
	TEST_CLASS(UnitTestRBTree)
	{
	public:
		RBTree<int, char> tree;
		int* keys;
		int* keysTree;
		char* values;
		char* valuesTree;

		TEST_METHOD(insert_1)
		{
			tree.insert(1, 'c');
			keys = new int[1]{ 1 };
			keysTree = tree.get_keys();
			for (size_t i = 0; i < tree.getSize(); i++)
			{
				Assert::AreEqual(keys[i], keysTree[i]);
			}
		}
		TEST_METHOD(insert_3)
		{
			tree.insert(5, 'y');
			tree.insert(4, 'o');
			tree.insert(3, 'a');
			keys = new int[3]{ 4, 3, 5 };
			keysTree = tree.get_keys();
			for (size_t i = 0; i < tree.getSize(); i++)
			{
				Assert::AreEqual(keys[i], keysTree[i]);
			}
		}
		TEST_METHOD(remove)
		{
			tree.insert(1, 'c');
			tree.insert(2, 'l');
			tree.insert(3, 'o');
			tree.insert(4, 'w');
			tree.insert(5, 'n');
			tree.remove(3);
			keys = new int[4]{ 2, 1, 4, 5 };
			keysTree = tree.get_keys();
			for (size_t i = 0; i < tree.getSize(); i++)
			{
				Assert::AreEqual(keys[i], keysTree[i]);
			}
		}
		TEST_METHOD(remove_error_double_remove)
		{
			tree.insert(1, 'q');
			tree.insert(2, 'w');
			try
			{
				tree.remove(2);
				tree.remove(2);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Element not found", e.what());
			}
		}
		TEST_METHOD(remove_error_empty_tree)
		{
			try
			{
				tree.remove(1);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Element not found", e.what());
			}
		}
		TEST_METHOD(find)
		{
			tree.insert(1, 's');
			tree.insert(2, 'e');
			tree.insert(3, 'a');
			tree.insert(4, 'r');
			tree.insert(5, 'c');
			tree.insert(6, 'h');
			values = new char[6]{ 's','e','a','r','c','h' };
			for (size_t i = 0; i < tree.getSize(); i++)
			{
				Assert::AreEqual(tree.find(i + 1), values[i]);
			}
		}
		TEST_METHOD(find_error_out_of_range)
		{
			tree.insert(1, 'e');
			tree.insert(2, 'r');
			try
			{
				tree.find(4);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Element not found", e.what());
			}
		}
		TEST_METHOD(find_error_tree_empty)
		{
			try
			{
				tree.find(6);
			}
			catch (std::out_of_range e)
			{
				Assert::AreEqual("Element not found", e.what());
			}
		}
		TEST_METHOD(get_keys)
		{
			tree.insert(1, 'c');
			tree.insert(2, 'a');
			tree.insert(3, 't');
			keys = new int[3]{ 2, 1, 3 };
			keysTree = tree.get_keys();
			for (size_t i = 0; i < tree.getSize(); i++)
			{
				Assert::AreEqual(keys[i], keysTree[i]);
			}
		}
		TEST_METHOD(get_values)
		{
			tree.insert(1, 'f');
			tree.insert(2, 'i');
			tree.insert(3, 'n');
			tree.insert(4, 'd');
			values = new char[4]{ 'i', 'f', 'n', 'd' };
			valuesTree = tree.get_values();
			for (size_t i = 0; i < tree.getSize(); i++)
			{
				Assert::AreEqual(values[i], valuesTree[i]);
			}
		}
		TEST_METHOD(clear)
		{
			tree.insert(1, 't');
			tree.insert(2, 'y');
			tree.clear();
			tree.insert(3, 'u');
			tree.insert(4, 'i');
			values = new char[2]{ 'u','i' };
			valuesTree = tree.get_values();
			for (size_t i = 0; i < tree.getSize(); i++)
			{
				Assert::AreEqual(values[i], valuesTree[i]);
			}
		}
	};
}