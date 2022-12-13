/**
 * _islower - checks wether a c is lowercase or not
 * @c: character
 *
 * Return: 1 if c is lowercase, 0 otherwise
 */
int _islower(int c)
{
	return ((c >= 97) && (c <= 122) ? 1 : 0);
}
