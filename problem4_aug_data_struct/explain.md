**Code Choices :**
I chose to implement this list using a doubly linked list. While there are other ways that offer faster searching, the doubly linked list makes inserting and deleting super simple. The reason I chose this is becuase I saw the requirement for insterting and deleting before I saw the sorting lol. 

I made a Node struct with data to store the integer and then ponters to next and previous nodes. I made a list struct to hold the Nodes with a head and the tail so I can instert and delete easily at both the head and the tail. As I was going I decided to add in a size attribute to the list to make checking empty and getting the size of the list O(1). I chose to use bubble sort for sorting in Asc and Desc order becuase it was the simplest implemenation when using a linked list. Also, for the return hightest Integer. I chose to go through the list linearly because we don't know if the list is sorted or not when this function is called.

**Utility: **
This is just a simple integer container that could be used across many programs needing flexible storage when the size of the list is constantly expanding. For example, this could be beefed up and used to store employees where the number is constantly changing with hireing and fireing. It could also be used for queues. 

Since this is super modular. It could easily be implemented into other projects where you need a dynamic list. However if it was a super large project I would most likely switch the sorting algorithm to something more efficient than bubble sort, like merge sort.
