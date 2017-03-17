

int main() {
    /* The text to find */
    static const char text_to_find[] = "xyz";

    /* The text to replace it with */
    static const char text_to_replace[] = "abc";

    char *pos = strstr(buffer, text_to_find);
    if (pos != NULL) {
        /* Allocate memory for temporary buffer */
        char *temp = calloc(strlen(buffer) - strlen(text_to_find) + strlen(text_to_replace) + 1, 1);

        /* Copy the text before the text to replace */
        memcpy(temp, buffer, pos - buffer);

        /* Copy in the replacement text */
        memcpy(temp + (pos - buffer), text_to_replace, strlen(text_to_replace));

        /* Copy the remaining text from after the replace text */
        memcpy(temp + (pos - buffer) + strlen(text_to_replace),
               pos + strlen(text_to_find),
               1 + strlen(buffer) - ((pos - buffer) + strlen(text_to_find)));

        fputs(temp, output);

        free(temp);
    } else {
        fputs(buffer, output);
    }

    fclose(output);
    fclose(input);

    /* Rename the temporary file to the original file */
    rename("input.txt", "temp.txt");
}