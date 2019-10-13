Section 1 (Program Creation):

PE-Import.exe is a relativly simple program that checks if a file of the name "PE-1.txt" is in its root directory. If it is, and contains the string "I want to learn PE file format!" it is printed to standard output, otherwise the string is appended to the file if present, or a new file created.

Section 2 (Packing):

PE-Import_Packed.exe is a packed version of PE-Import (packed using UPX).

![Import Tables](HW_2_Q1/Attachments/Imports.png)

Packing the executable resulted in a reduced file size and the Name RVA / FirstThunk of the import table entries changed (though description/name remained constant).

Section 3 (False Positive - Virus Total):

By packing our exe, we triggered a false positive on 6 antivirus engines (compared to 1 on the original):

Normal: https://www.virustotal.com/gui/file/ce68b25d5ef39e97aef5136a72836eb11835c80f3e7dd6ebdbf58bccaf0431cf/detection
Packed: https://www.virustotal.com/gui/file/0d6fabf472f541323d2249186652c6549cbd672cb1bb50a17239c34791b0f777/detection
