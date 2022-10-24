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

from game import Agent

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
            if ghostState.scaredTimer > dist: # killable
                ghostScores.append(1e9)
            elif dist <= 1: # ghost on adjacent cell
                ghostScores.append(-1e9)
            else:
                ghostScores.append(0)
        newFoodList = newFood.asList()
        foodScores = []
        for foodPos in newFoodList:
            dist = manhattanDistance(newPos, foodPos)
            foodScores.append(dist)
        return successorGameState.getScore() + min(ghostScores) + 1.0/min(foodScores, default=1e9)
    
        # + (1.0/(1.0 + min(foodScores, default=1e9)))
        # return successorGameState.getScore()

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
        return self.value(gameState, 0, self.depth)[1]
        # util.raiseNotDefined()
    def value(self, gameState, agentIndex, depth):
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState), Directions.STOP
        elif agentIndex == 0:
            return self.maxValue(gameState, agentIndex, depth)
        else:
            return self.minValue(gameState, agentIndex, depth)

    def minValue(self, gameState, agentIndex, depth):
        nextAgent = (agentIndex + 1) % gameState.getNumAgents()
        if nextAgent == 0:
            nextDepth = depth - 1
        else:
            nextDepth = depth
        
        selectedScore, selectedAction = 1e9, Directions.STOP
        actionList = gameState.getLegalActions(agentIndex)
        for action in actionList:
            successorState = gameState.generateSuccessor(agentIndex, action)
            successorScore = self.value(successorState, nextAgent, nextDepth)[0]
            if selectedScore > successorScore:
                selectedScore = successorScore
                selectedAction = action
        return selectedScore, selectedAction

    def maxValue(self, gameState, agentIndex, depth):
        nextAgent = (agentIndex + 1) % gameState.getNumAgents()
        if nextAgent == 0:
            nextDepth = depth - 1
        else:
            nextDepth = depth
        
        selectedScore, selectedAction = -1e9, Directions.STOP
        actionList = gameState.getLegalActions(agentIndex)
        for action in actionList:
            successorState = gameState.generateSuccessor(agentIndex, action)
            successorScore = self.value(successorState, nextAgent, nextDepth)[0]
            if selectedScore < successorScore:
                selectedScore = successorScore
                selectedAction = action
        return selectedScore, selectedAction

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        return self.value(gameState, 0, self.depth, -1e9, 1e9)[1]
        # util.raiseNotDefined()
        
    def value(self, gameState, agentIndex, depth, alpha, beta):
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState), Directions.STOP
        elif agentIndex == 0:
            return self.maxValue(gameState, agentIndex, depth, alpha, beta)
        else:
            return self.minValue(gameState, agentIndex, depth, alpha, beta)

    def minValue(self, gameState, agentIndex, depth, alpha, beta):
        nextAgent = (agentIndex + 1) % gameState.getNumAgents()
        if nextAgent == 0:
            nextDepth = depth - 1
        else:
            nextDepth = depth
        
        selectedScore, selectedAction = 1e9, Directions.STOP
        actionList = gameState.getLegalActions(agentIndex)
        for action in actionList:
            successorState = gameState.generateSuccessor(agentIndex, action)
            successorScore = self.value(successorState, nextAgent, nextDepth, alpha, beta)[0]
            if selectedScore > successorScore:
                selectedScore = successorScore
                selectedAction = action
            if selectedScore < alpha:
                return selectedScore, selectedAction
            beta = min(beta, successorScore)
        return selectedScore, selectedAction

    def maxValue(self, gameState, agentIndex, depth, alpha, beta):
        nextAgent = (agentIndex + 1) % gameState.getNumAgents()
        if nextAgent == 0:
            nextDepth = depth - 1
        else:
            nextDepth = depth
        
        selectedScore, selectedAction = -1e9, Directions.STOP
        actionList = gameState.getLegalActions(agentIndex)
        for action in actionList:
            successorState = gameState.generateSuccessor(agentIndex, action)
            successorScore = self.value(successorState, nextAgent, nextDepth, alpha, beta)[0]
            if selectedScore < successorScore:
                selectedScore = successorScore
                selectedAction = action
            if selectedScore > beta:
                return selectedScore, selectedAction
            alpha = max(alpha, successorScore)
        return selectedScore, selectedAction

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
        return self.value(gameState, 0, self.depth)[1]
        # util.raiseNotDefined()
        
    def value(self, gameState, agentIndex, depth):
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState), Directions.STOP
        elif agentIndex == 0:
            return self.maxValue(gameState, agentIndex, depth)
        else:
            return self.minValue(gameState, agentIndex, depth)
    
    def minValue(self, gameState, agentIndex, depth):
        nextAgent = (agentIndex + 1) % gameState.getNumAgents()
        if nextAgent == 0:
            nextDepth = depth - 1
        else:
            nextDepth = depth
        
        selectedScore, selectedAction = 1e9, Directions.STOP
        actionList = gameState.getLegalActions(agentIndex)
        numLegalMoves = len(actionList)
        v = 0
        p = 1.0/float(numLegalMoves)
        for action in actionList:
            successorState = gameState.generateSuccessor(agentIndex, action)
            successorScore = self.value(successorState, nextAgent, nextDepth)[0]
            v +=  successorScore
        v /= numLegalMoves
        return v, selectedAction
    
    def maxValue(self, gameState, agentIndex, depth):
        nextAgent = (agentIndex + 1) % gameState.getNumAgents()
        if nextAgent == 0:
            nextDepth = depth - 1
        else:
            nextDepth = depth
        
        selectedScore, selectedAction = -1e9, Directions.STOP
        actionList = gameState.getLegalActions(agentIndex)
        for action in actionList:
            successorState = gameState.generateSuccessor(agentIndex, action)
            successorScore = self.value(successorState, nextAgent, nextDepth)[0]
            if selectedScore < successorScore:
                selectedScore = successorScore
                selectedAction = action
        return selectedScore, selectedAction

def betterEvaluationFunction(currentGameState):
    """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (question 5).

    DESCRIPTION: <write something here so we know what you did>
    """
    "*** YOUR CODE HERE ***"
    newPos = currentGameState.getPacmanPosition()
    newGhostStates = currentGameState.getGhostStates()
    newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]
    newFoodlist = currentGameState.getFood().asList()
    ghostPoslist = [(ghost.getPosition()[0],ghost.getPosition()[1]) for ghost in newGhostStates]
    ghostDists = []
    for ghostState in newGhostStates:
            dist = manhattanDistance(newPos, ghostState.getPosition())
            ghostDists.append(dist)
    # newFoodList = newFood.asList()
    foodDists = []
    for foodPos in newFoodlist:
        dist = manhattanDistance(newPos, foodPos)
        foodDists.append(dist)
    if min(newScaredTimes) == 0 and (min(ghostDists) or currentGameState.isLose()):
        return -1e9
    if min(foodDists) == 0:
        return 1e9
    evalValue = 0
    capsuleDists = []
    if len(currentGameState.getCapsules()):
        # 
    # util.raiseNotDefined()

# Abbreviation
better = betterEvaluationFunction
