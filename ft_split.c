#include "push_swap.h"

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*result;

	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!(result))
		return (0);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static char	**ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_count_word(s, c);
	result = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!(result))
		return (0);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		word_len = ft_wor_dlen(s, c);
		result[i] = ft_strndup(s, word_len);
		if (!(result[i]))
			return (ft_free_arr(result, i - 1));
		s += word_len;
		i++;
	}
	return (result);
}