Question 1 - Alter Program Behavior:

Normally, the CrackMe software compares a given name to a given serial number. If the two values equate (given some unknown internal algorithm), the user is presented with a success message. Otherwise, the user is presented witha denial message.

Our goal is to change the program so that, even when incorrect credentials are entered, the behavior for a successful case (the message box stating "Great work, mate!") is still displayed.

This is simple enough. First we have to determine what logic is triggering the rejection message. To do that we find the rejection message in the diassembled code, and analyze its calling function:

![MESSAGE_BOXES](Attachments/HW3_P1_Q1_MESSAGE_BOXES.png)

![CALLING_FUNCTION](Attachments/HW3_P1_Q1_CALLING_FUNCTION.png)

We then simply re-write the calling instruction to load the desired messagebox instead:

![MODIFICATION](Attachments/HW3_P1_Q1_MODIFICATION.png)

Now, any name entered with any serial number will be evaluated as a successful combination. The modified binary is labeled CRACKME_CRACKED_BINARY.exe

--

Question 2 - Determine Credential Auditing Algorithm:

The first step in determining how serial numbers are matched to names is to find what calls the successfull message box.

![SERIAL](Attachments/HW3_P1_Q2_SERIAL.png)
