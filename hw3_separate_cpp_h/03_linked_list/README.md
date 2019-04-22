## Implement LinkedList::Insert
```
LinkedList list;
list.Insert(0, 3);
list.Insert(1, 5);
list.Insert(2, 6);
list.Insert(0, 1);
list.Insert(1, 4);
list.Insert(list.size(), 8);

./main
3
3->5
3->5->6
1->3->5->6
1->4->3->5->6
1->4->3->5->6->8

```
