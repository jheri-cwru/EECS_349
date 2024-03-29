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

![CALLTREE](Attachments/HW3_P1_Q2_CALLTREE.png)

So it appears that the last step in the algorithm is to check if EAX and EBX registers are equal - so now we know where to look for modification of data.

If we follow the calls before this comparison we notice more interesting information:

![CALLTREE](Attachments/HW3_P1_Q2_SERIAL.png)

It seems that our entered serial is being XOR'd with 1234 to give us our codified username.

Now we know how the serial is checked, we just have to determine what modifications the username undergoes (if any) before this XOR step.

After digging through some function calls, it becomes apparent that:
- The username is being encoded to the ASCII values of the charecters entered.
- This representation is added together.
- This summation is XOR'd with the arbitrary hex key "5678".

Putting together what we know, the algorithm for the serialization of a username is as follows:

- Get username from user (ASCII Representation)
- Convert username to uppercase (ASCII Representation)
- Sum ASCII representation of username
- XOR summation with 5678.
- XOR hex representation of serial with 1234.
- Check that both XOR results match.

So, for example, the following would be username-serial pairs:

JOSH: 17784

YUJIE: 17866

SHIFU: 17715

YIMING: 17793
