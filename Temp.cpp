#define ULONG long
#define LIST_ENTRY void*
#define QWORD long long

struct Table{
    QWORD Member1;  //Nonzero when the table has elements.
    LIST_ENTRY* LLHead;
    LIST_ENTRY* UnknownEntry;
    LIST_ENTRY* LastElementFound;
    ULONG LastIndexFound;
    ULONG NumberOfElements;
    QWORD Member7;
    QWORD Member8;
    QWORD Member9;    
};

void* MyRtlGetElementGenerictable(Table* table, ULONG index)
{
    // Init Vars:
    ULONG numberOfElements = table->NumberOfElements;
    LIST_ENTRY *elementFound = table->LastElementFound;
    ULONG lastIndexFound = table->LastIndexFound;
    ULONG adjustedIndex = index + 1;

    // Validate index:
    if (index == -1 || adjustedIndex > numberOfElements){
        return 0;
    }        

    // Don't find element if it's the last element found.
    if (adjustedIndex != lastIndexFound)
    {
        // If our element isn't lastElementFound, find it:
        if (lastIndexFound > adjustedIndex)
        {
            // Find which way to search:
            ULONG halfWay = lastIndexFound / 2;
            if (adjustedIndex > halfWay)
            {
                // Start at lastElementFound and move backwards towards the beginning:
                ULONG elementsToGo = lastIndexFound - adjustedIndex;                
                while(elementsToGo--){
                    elementFound = elementFound->Blink;
                }                
            }
            else
            {
                // Start at the beginning and move forward:
                ULONG elementsToGo = adjustedIndex;
                elementFound = (LIST_ENTRY *) &table->LLHead;
                
                while(elementsToGo--){
                    elementFound = elementFound->Flink;
                }                
            }
        }
        // Index is greater than the lastIndexFound:
        else
        {            
            ULONG elementsToLastFound = adjustedIndex - lastIndexFound;
            ULONG elementsToEnd = numberOfElements - adjustedIndex + 1;

            // Check if the index is closer to the lastIndexFound or the end of the list:
            if (elementsToLastFound <= elementsToEnd)
            {
                // The requested index is closer to the last element found.
                // Search the list forward starting at lastElementFound:
                while (elementsToLastFound--){
                    elementFound = elementFound->Flink;
                }
            }
            // The element is close to the end of the list than the last element found:
            else
            {
                // Start at the list head and search backwards:
                elementFound = (LIST_ENTRY *) &table->LLHead;
                while (elementsToEnd--){
                    elementFound = elementFound->Blink;
                }                
            }
        }
        // Save the element and index found into the table:    
        table->LastelementFound = elementFound;
        table->LastElementIndex = adjustedIndex;
    }

    // Skip the header and return the found element:
    return elementFound + 0x10;
}