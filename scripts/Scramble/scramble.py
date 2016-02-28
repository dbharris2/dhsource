import operator

dictionary = {}
board = []
board_size = 4
results = {}

letters = {
			'a' : 1,
			'b' : 4,
			'c' : 4,
			'd' : 2,
			'e' : 1,
			'f' : 4,
			'g' : 3,
			'h' : 3,
			'i' : 1,
			'j' : 10,
			'k' : 5,
			'l' : 2,
			'm' : 4,
			'n' : 2,
			'o' : 1,
			'p' : 4,
			'q' : 10,
			'r' : 1,
			's' : 1,
			't' : 1,
			'u' : 2,
			'v' : 5,
			'w' : 2,
			'x' : 8,
			'y' : 3,
			'z' : 1,
		}

class Piece:
	def __init__(self, letter, word_multiplier_value):
		self.letter                  = letter
		self.word_multiplier_value   = word_multiplier_value
		self.visited                 = False

def print_board(board):
	for row in board:
		for piece in row:
			print piece.letter,
		print
		
def is_valid_char(c):
	if not c in letters:
		return False
	return True

def hash_dictionary():
	#f = open("/etc/dictionaries-common/words", "r")
	f = open("/home/devon/Downloads/enable1.txt", "r")
	for line in f.readlines():
		word = ""
		for letter in line:
			if is_valid_char(letter):
				word += letter
		dictionary[word] = True

def create_board():
	row = 0
	col = 0
	multiplier_value = 1

	for i in range (0, board_size):
		board.append([])
	
	print "Insert board line by line"
	for i in range (0, board_size):
		line = raw_input().split()
		for j in range (0, board_size):
			p = Piece(line[j], 1)
			board[i].append(p)
	
	print "Is there a word multiplier? (y/n)",
	ans = raw_input()
	if ans == "y":
		print "Multiplier row: (0-3)",
		row = int(raw_input())
		print "Multiplier col: (0-3)",
		col = int(raw_input())
		print "Multiplier value: (2 or 3)",
		multiplier_value = int(raw_input())
		
	board[row][col].word_multiplier_value = multiplier_value
		
def find_word(word, word_index, row, col, value, multiplier):
	if board[row][col].visited:
		return
	if word_index == len(word):
		if not word in results:
			results[word] = value * multiplier
		return
	
	curr_letter = word[word_index]
	board[row][col].visited = True
	
	# Up-Left
	if row > 0 and col > 0 and curr_letter == board[row-1][col-1].letter:
		find_word(word, word_index+1, row-1, col-1, \
			value + letters[curr_letter], \
			board[row-1][col-1].word_multiplier_value * multiplier)
	# Up
	if row > 0 and curr_letter == board[row-1][col].letter:
		find_word(word, word_index+1, row-1, col, \
			value + letters[curr_letter], \
			board[row-1][col].word_multiplier_value * multiplier)
	# Up-Right
	if row > 0 and col < board_size-1 and curr_letter == board[row-1][col+1].letter:	
		find_word(word, word_index+1, row-1, col+1, \
			value + letters[curr_letter], \
			board[row-1][col+1].word_multiplier_value * multiplier)
	# Right
	if col < board_size-1 and curr_letter == board[row][col+1].letter:
		find_word(word, word_index+1, row, col+1, \
			value + letters[curr_letter], \
			board[row][col+1].word_multiplier_value * multiplier)
	# Right-Down
	if row < board_size-1 and col < board_size-1 and curr_letter == board[row+1][col+1].letter:	
		find_word(word, word_index+1, row+1, col+1, \
			value + letters[curr_letter], \
			board[row+1][col+1].word_multiplier_value * multiplier)
	# Down
	if row < board_size-1 and curr_letter == board[row+1][col].letter:	
		find_word(word, word_index+1, row+1, col, \
			value + letters[curr_letter], \
			board[row+1][col].word_multiplier_value * multiplier)
	# Down-Left
	if row < board_size-1 and col > 0 and curr_letter == board[row+1][col-1].letter:	
		find_word(word, word_index+1, row+1, col-1, \
			value + letters[curr_letter], \
			board[row+1][col-1].word_multiplier_value * multiplier)
	# Left
	if col > 0 and curr_letter == board[row][col-1].letter:
		find_word(word, word_index+1, row, col-1, \
			value + letters[curr_letter], \
			board[row][col-1].word_multiplier_value * multiplier)
		
	board[row][col].visited = False
		
def find_words():
	for word in dictionary:
		if len(word) <= 1:
			continue
		if len(word) > (board_size * board_size):
			continue
		for row in range (0, board_size):
			for letter in range (0, board_size):
				if board[row][letter].letter == word[0]:
					find_word(word, 1, row, letter, \
						letters[board[row][letter].letter], \
						board[row][letter].word_multiplier_value)
		
def print_results():
	sorted_results = sorted(results.iteritems(), key=operator.itemgetter(1))
	for word in sorted_results:
		print word[0], word[1]
		
hash_dictionary()
create_board()
find_words()
print_results()
