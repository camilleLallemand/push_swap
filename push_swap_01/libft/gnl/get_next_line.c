#include"get_next_line.h" 
 
size_t  ft_strlen(const char *s)
{ 
        size_t  i; 
 
        i = 0; 
        if (!s) 
                return (0); 
        while (s[i] != '\0') 
                i++; 
        return (i); 
} 
 
char    *ft_strchr(char *s, int c) 
{ 
        int     i; 
 
        i = 0; 
        if (!s) 
                return (0); 
        if (c == '\0') 
                return ((char *)&s[ft_strlen(s)]); 
        while (s[i] != '\0') 
        { 
                if (s[i] == (char) c) 
                        return ((char *)&s[i]); 
                i++; 
        } 
        return (0); 
} 
 
char    *ft_strjoin(char *left_str, char *buff) 
{ 
        size_t  i; 
        size_t  j; 
        char    *str; 
 
        if (!left_str) 
        { 
                left_str = (char *)malloc(1 * sizeof(char)); 
                left_str[0] = '\0'; 
        } 
        //if (!left_str || !buff)
        //       return (NULL);
        str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1)); 
        if (str == NULL)
                return (NULL);
        i = -1; 
        j = 0; 
        if (left_str)
               while (left_str[++i] != '\0')
                        str[i] = left_str[i]; 
        while (buff[j] != '\0') 
                str[i++] = buff[j++]; 
        str[ft_strlen(left_str) + ft_strlen(buff)] = '\0'; 
        free(left_str); 
        return (str); 
} 
 
char *first_read(int fd, char *buff_stock) 
{ 
        int rd_stat; 
        char *temp; 
 
        rd_stat = 1; 
        temp = malloc(sizeof(char) * (BUFFER_SIZE + 1)); 
        if (!temp) 
                return (free(temp), free(buff_stock), NULL);
        while(!ft_strchr(buff_stock, '\n') && rd_stat != 0) 
        { 
                rd_stat = read(fd, temp, BUFFER_SIZE); 
                if (rd_stat == -1)
                {
                    free(temp);
                    free(buff_stock);
                    return (NULL);
                } 
                temp[rd_stat] = '\0'; 
                buff_stock = ft_strjoin(buff_stock, temp); 
        }
        if (rd_stat == 0)
            return (free(buff_stock) ,free(temp), NULL);
        free (temp);
        return (buff_stock); 
} 
 
int     ft_strfnd( char *buff_stock, char **word) 
{ 
        size_t i; 
 
        i = 0; 
        while(buff_stock[i] && buff_stock[i] != '\n') 
                i++; 
        *word = malloc(sizeof(char) * (i + 2)); 
        if (!(*word)) 
                return (free(buff_stock),free( word), -1); 
        return 1; 
} 
 
char *ft_get_line(char *buff_stock, char **word) 
{ 
        size_t  i; 
        size_t  j; 
        char *temp; 

        j = 0;
        i = 0;
        if (!buff_stock || ft_strfnd(buff_stock, word) == -1)
                return (free (buff_stock), free(word),NULL);
        while(buff_stock[i] && buff_stock[i] != '\n')
        {
                (word[0][i]) = buff_stock[i];
                i++;
        }
        if (buff_stock[i] == '\n')
        {
                (word[0][i]) = '\n';
                i++;
        }
        (word[0][i]) = '\0';
        temp = malloc(sizeof(char) * (ft_strlen(buff_stock) - i + 1));
        if (!temp)
                return (free(buff_stock), free(word),NULL);
        while (buff_stock[i])
        {
                temp[j] = buff_stock[i];
                j++;
                i++;
        }
        temp[j] = '\0';
        free(buff_stock);
        return temp;
}

char *get_next_line(int fd)
{
        static char *buff_stock;
        char *word;

        if (BUFFER_SIZE < 1 || fd <= 0)
	    {
		    if (buff_stock)
			    free(buff_stock);
                    return (NULL);
	    }
        buff_stock = first_read(fd, buff_stock);
        if (!buff_stock)
	    {
                   return (NULL);
	    }
        buff_stock = ft_get_line(buff_stock, &word);
        if (!buff_stock)
	    {
		    free(word);
                    return(NULL);
	    }
        if (!word)
	    {
		    if (buff_stock)
			    free(buff_stock);
		    return (NULL);
	    }
        if (word[0] == '\0')
        {
            free(buff_stock);
        }
        return word;

}
/*
int main(void)
{
        int f;
        int i = 0;
	char *d;
        f = open("stock/tixt", O_RDONLY);
        while(i != 1)
        {
              printf("%s", d=get_next_line(f));
              i++;
		      free (d);
        }
        return 0;
}*/
