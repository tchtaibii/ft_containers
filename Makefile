FLAGS = -Wall -Wextra -Werror
CC = clang++
all :	
	@$(CC) $(FLAGS) vector/main.cpp -o vector/vector -std=c++98 && ./vector/vector
	@$(CC) $(FLAGS) ./stack/main.cpp -o stack/stack -std=c++98 && ./stack/stack
	@$(CC) $(FLAGS) ./map/main.cpp -o map/map -std=c++98 && ./map/map
	@$(CC) $(FLAGS) ./set/main.cpp -o set/set -std=c++98 && ./set/set
	@tput setaf 2; echo "ft_containers is tested"

clean :
	@rm -f ./vector/vector ./stack/stack ./map/map ./set/set
	@tput setaf 1; echo "CLEAN COMPLET"
fclean : clean 
re: fclean all