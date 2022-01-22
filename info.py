from random import seed, sample, choice
from os import linesep
from string import punctuation
from math import sqrt
from itertools import product



SEED_NUMBER = 1024
seed(SEED_NUMBER)
MAP_SIZE = 100
all_possible_symbols = frozenset(punctuation+'GSFT ')


def define_possible_objects(choices=punctuation):
    chars = choices
    chars += 'G'
    chars += 'T'*3
    chars += 'F'*3
    return chars

def generate_object(itera, available_coordinates, occupied_coordinates):
    symbol = sample(itera, 1)
    coordinates = choice(available_coordinates)
    available_coordinates.remove(coordinates)
    occupied_coordinates.append(coordinates)
    return symbol, coordinates


def set_up():
    symbols1 = define_possible_objects(punctuation)
    symbols2 = define_possible_objects('^&*'*5)
    return symbols1, symbols2


def generate_available_coordinates(map_size):

  # Generate all possible coordinates using list comprehension
  # Coordinates start from (0,0).If map size is 100.It goes untill (99,99).Since we include  0,maximum coordinate will be map_size-1
  return [(i,j) for i in range(map_size) for j in range(map_size)]


def generate_empty_map(available_coordinates):
  # return the dictionary as stated in question
  return {(x,y):(" "  if (x!=0 or y!=0) else "S")  for x,y in  available_coordinates}


def get_unique_objects(galaxy_map):

    # insert your code here
    symbols = list(galaxy_map.values())
    # Use python set to retrive unique symbols
    return frozenset(set(symbols))


# Refer to python set operations for below functions
def symbols_not_used_in_galaxy(symbols_in_galaxy):
    # use symmetric difference operator of sets to find symbols not used
    not_used = set(all_possible_symbols)^set(symbols_in_galaxy)
    return frozenset(not_used)


def common_objects_encountered(galaxy_1_objects, galaxy_2_objects):
    return frozenset(set(galaxy_1_objects).intersection(set(galaxy_2_objects)))


def objects_encountered_in_galaxy1_not_galaxy2(galaxy_1_objects, galaxy_2_objects):
    # insert your code here
    # USe set difference operator to get the objects
    return frozenset(set(galaxy_1_objects)-(set(galaxy_2_objects)))
    

def objects_encountered_in_galaxy2_not_galaxy1(galaxy_1_objects, galaxy_2_objects):

    # insert your code here
    # USe set difference operator to get the objects
   return frozenset(set(galaxy_2_objects)-(set(galaxy_1_objects)))


def objects_encountered_in_both_galaxys(galaxy1_objects, galaxy2_objects):
    # insert your code here
    return frozenset(set(galaxy1_objects).union(set(galaxy2_objects)))


def calculate_path_to_goal(sorted_object_list):
    objects_of_interest = []
    # loop throught the object list and append objects of interest to our resultant list
    for coordinates,distance,symbol in sorted_object_list:
      if symbol[0]== 'F' or symbol[0]== 'T':
        objects_of_interest.append([coordinates,distance,symbol])
    # Sort the list by distance and return it
    objects_of_interest.sort(key= lambda x:x[1])
    return objects_of_interest  


def display_galaxy(galaxy_map):
  result_string =""
  for symbols in galaxy_map.values():
    result_string+=symbols
  print(result_string)


def calculate_euclidean_distance(coordinates):
    # insert your code here
    return int(sqrt((coordinates[0]*2)+(coordinates[1]*2)))


def populate_galaxy_map(available_symbols, available_coordinates, occupied_coordinates, galaxy_map):
    objects_encountered_list = list()
    while True:
        symbol, coordinates = generate_object(available_symbols, available_coordinates, occupied_coordinates)
        distance = calculate_euclidean_distance(coordinates)
        # append the object to our list
        objects_encountered_list.append((coordinates,distance,symbol))
        # update our  galaxy_map
        galaxy_map[coordinates] = symbol[0]
        # break when we acheive goal
        if symbol[0] == "G":
          break
        # insert your code here
    # Sort objects by distance
    objects_encountered_list.sort(key = lambda x:x[1])
    return objects_encountered_list


def run_exploration():
    available_symbols1, available_symbols2 = set_up()
    available_coordinates1 = generate_available_coordinates(MAP_SIZE)
    available_coordinates2 = generate_available_coordinates(MAP_SIZE)
    occupied_coordinates1 = list()
    occupied_coordinates2 = list()
    galaxy_map_1 = generate_empty_map(available_coordinates1)
    galaxy_map_2 = generate_empty_map(available_coordinates2)
    explorer1_list = populate_galaxy_map(available_symbols1, available_coordinates1, occupied_coordinates1, galaxy_map_1)
    explorer2_list = populate_galaxy_map(available_symbols2, available_coordinates2, occupied_coordinates2, galaxy_map_2)
    print(explorer1_list)
    print(explorer2_list)
    path_list1 = calculate_path_to_goal(explorer1_list)
    print(path_list1)
    path_list2 = calculate_path_to_goal(explorer2_list)
    print(path_list2)
    display_galaxy(galaxy_map_1)
    display_galaxy(galaxy_map_2)
    galaxy2_symbols = get_unique_objects(galaxy_map_2)
    galaxy1_symbols = get_unique_objects(galaxy_map_1)
    print(galaxy1_symbols)
    print(galaxy2_symbols)

