# multiAgents.py
# --------------
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


from util import manhattanDistance
from game import Directions
import random, util
import math

from game import Agent
from searchAgents import mazeDistance, FoodSearchProblem, foodHeuristic

class ReflexAgent(Agent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
    """


    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {NORTH, SOUTH, WEST, EAST, STOP}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        "*** YOUR CODE HERE ***"
        ghostScores = []
        for ghostState in newGhostStates:
            dist = manhattanDistance(newPos, ghostState.getPosition())
            if ghostState.scaredTimer > dist:
                ghostScores.append(math.inf)
            elif dist <= 1:
                ghostScores.append(-1 * math.inf)
            else:
                ghostScores.append(0)
        newFoodList = newFood.asList()
        foodScores = []
        for foodPos in newFoodList:
            dist = manhattanDistance(newPos, foodPos)
            foodScores.append(dist)
        return successorGameState.getScore() + min(ghostScores) + (1.0/(1.0 + min(foodScores, default=math.inf)))

def scoreEvaluationFunction(currentGameState):
    """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Your minimax agent (question 2)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action from the current gameState using self.depth
        and self.evaluationFunction.

        Here are some method calls that might be useful when implementing minimax.

        gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

        gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

        gameState.getNumAgents():
        Returns the total number of agents in the game

        gameState.isWin():
        Returns whether or not the game state is a winning state

        gameState.isLose():
        Returns whether or not the game state is a losing state
        """
        "*** YOUR CODE HERE ***"
        def minimax(state, depth, agent):
            nextDepth = depth
            if agent == 0:
                nextDepth -= 1
            if nextDepth == 0 or state.isWin() or state.isLose():
                return self.evaluationFunction(state), None
            nextAgent = (agent + 1) % state.getNumAgents()
            bestAction = None
            if agent == 0:
                maxm = -math.inf
                for action in state.getLegalActions(agent):
                    successorState = state.generateSuccessor(agent, action)
                    value, _ = minimax(successorState, nextDepth, nextAgent)
                    if max(maxm, value) == value:
                        maxm = value
                        bestAction = action
                return maxm, bestAction
            else:
                minm = math.inf
                for action in state.getLegalActions(agent):
                    successorState = state.generateSuccessor(agent, action)
                    value, _ = minimax(successorState, nextDepth, nextAgent)
                    if min(minm, value) == value:
                        minm = value
                        bestAction = action
                return minm, bestAction
        value, action = minimax(gameState, self.depth + 1, self.index)
        return action
        # util.raiseNotDefined()

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        def alphaBetaPruning(state, depth, alpha, beta, agent):
            nextDepth = depth
            if agent == 0:
                nextDepth -= 1
            if nextDepth == 0 or state.isWin() or state.isLose():
                return self.evaluationFunction(state), None
            nextAgent = (agent + 1) % state.getNumAgents()
            bestAction = None
            if agent == 0:
                maxm = -math.inf
                for action in state.getLegalActions(agent):
                    successorState = state.generateSuccessor(agent, action)
                    value, _ = alphaBetaPruning(successorState, nextDepth, alpha, beta, nextAgent)
                    if max(maxm, value) == value:
                        maxm = value
                        bestAction = action
                    if maxm > beta:
                        return maxm, bestAction
                    alpha = max(alpha, maxm)
                return maxm, bestAction
            else:
                minm = math.inf
                for action in state.getLegalActions(agent):
                    successorState = state.generateSuccessor(agent, action)
                    value, _ = alphaBetaPruning(successorState, nextDepth, alpha, beta, nextAgent)
                    if min(minm, value) == value:
                        minm = value
                        bestAction = action
                    if minm < alpha:
                        return minm, bestAction
                    beta = min(beta, minm)
                return minm, bestAction
        value, action = alphaBetaPruning(gameState, self.depth + 1, -math.inf, math.inf, self.index)
        return action
        # util.raiseNotDefined()

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState):
        """
        Returns the expectimax action using self.depth and self.evaluationFunction

        All ghosts should be modeled as choosing uniformly at random from their
        legal moves.
        """
        "*** YOUR CODE HERE ***"
        agent = self.index
        if agent != 0:
            return random.choice(gameState.getLegalActions(agent))
        def expectimax(state, depth, agent):
            nextDepth = depth
            if agent == 0:
                nextDepth -= 1
            if nextDepth == 0 or state.isWin() or state.isLose():
                return self.evaluationFunction(state), None
            nextAgent = (agent + 1) % state.getNumAgents()
            bestAction = None
            legalMoves = state.getLegalActions(agent)
            if agent != 0:
                p = 1.0/float(len(legalMoves))
                value = 0
                for action in legalMoves:
                    successorState = state.generateSuccessor(agent, action)
                    expectedValue, _ = expectimax(successorState, nextDepth, nextAgent)
                    value += p * expectedValue
                return value, None
            else:
                maxm = -math.inf
                bestAction = None
                for action in legalMoves:
                    successorState = state.generateSuccessor(agent, action)
                    expectedValue, _ = expectimax(successorState, nextDepth, nextAgent)
                    if max(maxm, expectedValue) == expectedValue:
                        maxm = expectedValue
                        bestAction = action
                return maxm, bestAction
        _, action = expectimax(gameState, self.depth + 1, self.index)
        return action
        # util.raiseNotDefined()

def betterEvaluationFunction(currentGameState):
    """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (question 5).

    DESCRIPTION: <write something here so we know what you did>
    """
    "*** YOUR CODE HERE ***"
    # successorGameState = currentGameState.generatePacmanSuccessor(action)
    # newPos = successorGameState.getPacmanPosition()
    # newFood = successorGameState.getFood()
    # newGhostStates = successorGameState.getGhostStates()
    # newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]
    # ghostScores = []
    # for ghostState in newGhostStates:
    #     dist = mazeDistance(currentGameState, newPos, ghostState.getPosition())
    #     if ghostState.scaredTimer > dist:
    #         ghostScores.append(math.inf)
    #     elif dist <= 1:
    #         ghostScores.append(-1 * math.inf)
    #     else:
    #         ghostScores.append(0)
    # newFoodList = newFood.asList()
    # foodScores = []
    # for foodPos in newFoodList:
    #     dist = manhattanDistance(newPos, foodPos)
    #     foodScores.append(dist)
    # foodSearch = FoodSearchProblem(currentGameState)
    # numFoods = len(newFood.asList())
    # foodEaten = len(foodSearch.start[1].asList()) - numFoods
    # return min(ghostScores) + (1.0/(1.0 + foodHeuristic((newPos, newFood), foodSearch))) + foodEaten
    newPos = currentGameState.getPacmanPosition()
    newGhostStates = currentGameState.getGhostStates()
    newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]
    newFoodlist = currentGameState.getFood().asList()
    ghostPoslist = [(ghost.getPosition()[0],ghost.getPosition()[1]) for ghost in newGhostStates]
    # fail:
    if min(newScaredTimes) <=0 and (newPos in ghostPoslist): return -1
    if currentGameState.isLose(): return -1
    # get food:
    if newPos in currentGameState.getFood().asList(): return 10
    # sort 2 list to find closest
    closestFoodlist = sorted(newFoodlist,key=lambda x: util.manhattanDistance(x,newPos))
    closestGhostlist = sorted(ghostPoslist,key=lambda y: util.manhattanDistance(y,newPos))
    
    value = 0
    # low capsule left boost, boost value 50 depends:
    if len(currentGameState.getCapsules()) < 2: value += 50

    if len(closestFoodlist) == 0 or len(closestGhostlist) == 0: # if empty, plainly credit 1
        value += scoreEvaluationFunction(currentGameState) + 1
    else: # 1/food dist -1/ghost dist
        value += (scoreEvaluationFunction(currentGameState)
        + 1/util.manhattanDistance(closestFoodlist[0],newPos) - 1/util.manhattanDistance(closestGhostlist[0],newPos))
    return value
    # util.raiseNotDefined()

# Abbreviation
better = betterEvaluationFunction
