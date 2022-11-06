# valueIterationAgents.py
# -----------------------
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


# valueIterationAgents.py
# -----------------------
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


import mdp, util
import numpy as np

from learningAgents import ValueEstimationAgent
import collections
import random

class ValueIterationAgent(ValueEstimationAgent):
    """
        * Please read learningAgents.py before reading this.*

        A ValueIterationAgent takes a Markov decision process
        (see mdp.py) on initialization and runs value iteration
        for a given number of iterations using the supplied
        discount factor.
    """
    def __init__(self, mdp, discount = 0.9, iterations = 100):
        """
          Your value iteration agent should take an mdp on
          construction, run the indicated number of iterations
          and then act according to the resulting policy.

          Some useful mdp methods you will use:
              mdp.getStates()
              mdp.getPossibleActions(state)
              mdp.getTransitionStatesAndProbs(state, action)
              mdp.getReward(state, action, nextState)
              mdp.isTerminal(state)
        """
        self.mdp = mdp
        self.discount = discount
        self.iterations = iterations
        self.values = util.Counter() # A Counter is a dict with default 0
        self.runValueIteration()

    def runValueIteration(self):
        # Write value iteration code here
        "*** YOUR CODE HERE ***"
        for k in range(self.iterations):
            V_k = self.values.copy()
            for s in self.mdp.getStates():
                Q = []
                for a in self.mdp.getPossibleActions(s):
                    newQ = 0
                    for s_, T in self.mdp.getTransitionStatesAndProbs(s, a):
                        R = self.mdp.getReward(s, a, s_)
                        newQ += T * (R +(self.discount * V_k[s_]))
                    Q.append(newQ)
                if len(Q):
                    self.values[s] = max(Q) # V_k+1

    def getValue(self, state):
        """
          Return the value of the state (computed in __init__).
        """
        return self.values[state]


    def computeQValueFromValues(self, state, action):
        """
          Compute the Q-value of action in state from the
          value function stored in self.values.
        """
        "*** YOUR CODE HERE ***"
        # util.raiseNotDefined()
        Q = 0
        for s_, T in self.mdp.getTransitionStatesAndProbs(state, action):
            R = self.mdp.getReward(state, action, s_)
            V = self.getValue(s_)
            Q += T * (R + (self.discount * V))
        return Q

    def computeActionFromValues(self, state):
        """
          The policy is the best action in the given state
          according to the values currently stored in self.values.

          You may break ties any way you see fit.  Note that if
          there are no legal actions, which is the case at the
          terminal state, you should return None.
        """
        "*** YOUR CODE HERE ***"
        # util.raiseNotDefined()
        maxQ = -np.inf
        maxA = None
        for a in self.mdp.getPossibleActions(state):
            Q = self.computeQValueFromValues(state, a)
            if Q > maxQ:
                maxQ = Q
                maxA = a
        return maxA

    def getPolicy(self, state):
        return self.computeActionFromValues(state)

    def getAction(self, state):
        "Returns the policy at the state (no exploration)."
        return self.computeActionFromValues(state)

    def getQValue(self, state, action):
        return self.computeQValueFromValues(state, action)

class AsynchronousValueIterationAgent(ValueIterationAgent):
    """
        * Please read learningAgents.py before reading this.*

        An AsynchronousValueIterationAgent takes a Markov decision process
        (see mdp.py) on initialization and runs cyclic value iteration
        for a given number of iterations using the supplied
        discount factor.
    """
    def __init__(self, mdp, discount = 0.9, iterations = 1000):
        """
          Your cyclic value iteration agent should take an mdp on
          construction, run the indicated number of iterations,
          and then act according to the resulting policy. Each iteration
          updates the value of only one state, which cycles through
          the states list. If the chosen state is terminal, nothing
          happens in that iteration.

          Some useful mdp methods you will use:
              mdp.getStates()
              mdp.getPossibleActions(state)
              mdp.getTransitionStatesAndProbs(state, action)
              mdp.getReward(state)
              mdp.isTerminal(state)
        """
        ValueIterationAgent.__init__(self, mdp, discount, iterations)

    def runValueIteration(self):
        "*** YOUR CODE HERE ***"
        states = self.mdp.getStates()
        # indices = random.sample(range(len(states)), len(states))
        i = 0
        for k in range(self.iterations):
            maxA = self.computeActionFromValues(states[i % len(states)])
            if maxA:
                self.values[states[i % len(states)]] = self.getQValue(states[i % len(states)], maxA)
            i = i + 1

class PrioritizedSweepingValueIterationAgent(AsynchronousValueIterationAgent):
    """
        * Please read learningAgents.py before reading this.*

        A PrioritizedSweepingValueIterationAgent takes a Markov decision process
        (see mdp.py) on initialization and runs prioritized sweeping value iteration
        for a given number of iterations using the supplied parameters.
    """
    def __init__(self, mdp, discount = 0.9, iterations = 100, theta = 1e-5):
        """
          Your prioritized sweeping value iteration agent should take an mdp on
          construction, run the indicated number of iterations,
          and then act according to the resulting policy.
        """
        self.theta = theta
        ValueIterationAgent.__init__(self, mdp, discount, iterations)

    def runValueIteration(self):
        "*** YOUR CODE HERE ***"
        states = self.mdp.getStates()
        parent = {}
        for s in states:
            parent[s] = set()
        for s in states:
            for a in self.mdp.getPossibleActions(s):
                for s_, T in self.mdp.getTransitionStatesAndProbs(s, a):
                    parent[s_].add(s)
        pq = util.PriorityQueue()
        for s in states:
            if not self.mdp.isTerminal(s):
                Q = []
                actions = self.mdp.getPossibleActions(s)
                for a in actions:
                    Q.append(self.computeQValueFromValues(s, a))
                diff = abs(self.values[s] - max(Q))
                pq.push(s, -diff)
        for i in range(self.iterations):
            if not pq.isEmpty():
                s = pq.pop()
                Q = []
                actions = self.mdp.getPossibleActions(s)
                for a in actions:
                    Q.append(self.computeQValueFromValues(s, a))
                self.values[s] = max(Q)
                for p in parent[s]:
                    Q = []
                    actions = self.mdp.getPossibleActions(p)
                    for a in actions:
                        Q.append(self.computeQValueFromValues(p, a))
                    diff = abs(self.values[p] - max(Q))
                    if diff > self.theta:
                        pq.update(p, -diff)




