#include <stdio.h>

int MoveDisk(int diskNumber, int startPost, int endPost, int midPost);

int main ()
{
	int diskNumber =3;
	int startPost =1;
	int endPost=3;
	int midPost=2;
	
	MoveDisk(diskNumber, startPost, endPost, midPost);
	
	return 0;
}

/* 
** Inputs
**   diskNumber is the disk to be moved (disk1 is smallest)
**   startPost is the post the disk is currently on
**   endPost is the post we want the disk to end on
**   midPost is the intermediate post
*/
int MoveDisk(int diskNumber, int startPost, int endPost, int midPost)
{
   if (diskNumber > 1) {
       /* Move n-1 disks off the current disk on         */
       /* startPost and put them on the midPost          */
       MoveDisk(diskNumber-1, startPost, midPost, endPost); 

       /* Move the largest disk.                         */
       printf("Move disk %d from post %d to post %d.\n", 
               diskNumber, startPost, endPost);

       /* Move all n-1 disks from midPost onto endPost   */
       MoveDisk(diskNumber-1, midPost, endPost, startPost);
   }
   else 
       printf("Move disk 1 from post %d to post %d.\n", 
               startPost, endPost);      
}
