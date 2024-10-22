# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        if actions == None: return 999999
        x,y= self.getStartState()
        cost = 0
        for action in actions:
            # Check figure out the next state and see whether its' legal
            dx, dy = Actions.directionToVector(action)
            x, y = int(x + dx), int(y + dy)
            if self.walls[x][y]: return 999999
            cost += self.costFn((x,y))
        return cost
        #util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

# def depthFirstSearch(problem):
#     """
#     Search the deepest nodes in the search tree first.

#     Your search algorithm needs to return a list of actions that reaches the
#     goal. Make sure to implement a graph search algorithm.

#     To get started, you might want to try some of these simple commands to
#     understand the search problem that is being passed in:

#     print("Start:", problem.getStartState())
#     print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
#     print("Start's successors:", problem.getSuccessors(problem.getStartState()))
#     """
#     "*** YOUR CODE HERE ***"
#     visited = set()
#     start_node = problem.getStartState()
#     unvisited = util.Stack()
#     unvisited.push((start_node, []))
#     while unvisited.isEmpty() == False:
#     	(current_state, path) = unvisited.pop()
#     	if problem.isGoalState(current_state) == True:
#     		return path
#     	elif current_state not in visited:
#     		visited.add(current_state)
#     		for (child, action, cost) in problem.getSuccessors(current_state):
#     			if child not in visited:
#     				unvisited.push((child, path + [action]))
#     #util.raiseNotDefined()

# def breadthFirstSearch(problem):
#     """Search the shallowest nodes in the search tree first."""
#     "*** YOUR CODE HERE ***"
#     visited = set()
#     start_node = problem.getStartState()
#     unvisited = util.Queue()
#     unvisited.push((start_node, []))
#     while unvisited.isEmpty() == False:
#     	(current_state, path) = unvisited.pop()
#     	if problem.isGoalState(current_state) == True:
#     		return path
#     	elif current_state not in visited:
#     		visited.add(current_state)
#     		for (child, action, cost) in problem.getSuccessors(current_state):
#     			if child not in visited:
#     				unvisited.push((child, path + [action]))
#     #util.raiseNotDefined()
def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print("Start:", problem.getStartState())
    print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
    print("Start's successors:", problem.getSuccessors(problem.getStartState()))
    """
    "*** YOUR CODE HERE ***"
    start_node = problem.getStartState()
    # unvisited = util.Stack()
    unvisited = util.PriorityQueue()
    priority = 0
    visited = set() # amortized O(1) look-up
    # unvisited.push((start_node, []))
    unvisited.push((start_node, [], 0), priority)
    priority -= 1
    while unvisited.isEmpty() == False:
        # (current_state, path) = unvisited.pop()
        (current_state, path, _) = unvisited.pop()
        priority += 1
        if problem.isGoalState(current_state) == True:
            return path
        elif current_state not in visited:
            visited.add(current_state)
            for (child, action, cost) in problem.getSuccessors(current_state):
                if child not in visited:
                    # unvisited.push((child, path + [action]))
                    unvisited.push((child, path + [action], 0), priority)
                    priority -= 1
    #util.raiseNotDefined()

def breadthFirstSearch(problem):
    """Search the shallowest nodes in the search tree first."""
    "*** YOUR CODE HERE ***"
    start_node = problem.getStartState()
    # unvisited = util.Queue()
    unvisited = util.PriorityQueue()
    priority = 0
    visited = set() # amortized O(1) look-up
    # unvisited.push((start_node, []))
    unvisited.push((start_node, [], 1), priority)
    priority += 1
    while unvisited.isEmpty() == False:
        # (current_state, path) = unvisited.pop()
        (current_state, path, _) = unvisited.pop()
        # priority -= 1
        if problem.isGoalState(current_state) == True:
            return path
        elif current_state not in visited:
            visited.add(current_state)
            for (child, action, cost) in problem.getSuccessors(current_state):
                if child not in visited:
                    # unvisited.push((child, path + [action]))
                    unvisited.push((child, path + [action], 1), priority)
                    priority += 1

def uniformCostSearch(problem):
    """Search the node of least total cost first."""
    "*** YOUR CODE HERE ***"
    visited = set()
    start_node = problem.getStartState()
    unvisited = util.PriorityQueue()
    #unvisited = util.PriorityQueueWithFunction(lambda x:problem.getCostOfAction(x[1]))
    #unvisited.push((start_node, []))
    unvisited.push((start_node, [], 0), 0)
    while unvisited.isEmpty() == False:
    	(current_state, path, cumulative_cost) = unvisited.pop()
    	if problem.isGoalState(current_state) == True:
    		return path
    	elif current_state not in visited:
    		visited.add(current_state)
    		for child, action, cost in problem.getSuccessors(current_state):
    			if child not in visited:
    				#unvisited.push((child, path + [action]))
    				unvisited.push((child, path + [action], cumulative_cost + cost), cumulative_cost + cost)
    #util.raiseNotDefined()

def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    "*** YOUR CODE HERE ***"
    util.raiseNotDefined()


# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
