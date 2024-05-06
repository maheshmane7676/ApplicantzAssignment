void reverseWord(char *Start,char *End)
{
    char letter;
    /*Swap each character in the word.*/
    while(Start < End)
    {
        letter = *Start;
        *Start++ = *End;
        *End-- = letter;
    }
}

/*This function reverses every word of the string.*/
char* reverse_words(char* s) {
    char *tempStr = NULL;
    char *wordStart = NULL;
    tempStr = s;

	/*Check if the give string is valid and not null*/
    while(tempStr != NULL )
    {
		/*At the very beginning of string check for spaces. Ignore if spaces and move to next character*/
        if(wordStart == NULL && *tempStr != ' ')
        {
			/*Assign address of first valid character/non-space*/
            wordStart = tempStr;
        }
        /*Once we have first character of string. check for next character space or end of string*/
        if(wordStart && ((*(tempStr + 1) == ' ') || (*(tempStr + 1) == '\0')))
        {
            /*If next character is space or end of string we have reached end of current word. Reverse it*/
            reverseWord(wordStart,tempStr);
            /*Move to next word.Skip space*/
            wordStart = tempStr+2;
        }
        /*Exit loop if we have reached end of string*/
        if(*(tempStr + 1) == '\0')
            break;
        /*Increment until we reach end of string*/
        tempStr++;
    }
	/*return reversed string*/
    return s;
}

void main()
{
	char *str = "String; 2be reversed...";
	/*Invoke function to reverse given string.*/
	reverse_words(str);
	/*All the reverse operations are performed on same memory address of original string.*/
	printf("Reversed string %s\n",str);
	return;
}
