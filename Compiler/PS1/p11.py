from tabulate import tabulate
from collections import defaultdict, deque

class DFA:
    def __init__(self, nfaStates, nfaAlphabet, nfaStart, nfaAccept, nfaTransition):
        self.nfaStates = nfaStates
        self.nfaAlphabet = nfaAlphabet
        self.nfaStart = nfaStart
        self.nfaAccept = nfaAccept
        self.nfaTransition = nfaTransition
        self.dfaStates = []
        self.dfaStart = None
        self.dfaAccept = set()
        self.dfaTranstion = {}
        self.stateMapping = {}

    def epsilonClosure(self, states):
        
        stack = list(states)
        closure = set(states)
        while stack:
            state = stack.pop()
            if (state, '') in self.nfaTransition:
                for nextState in self.nfaTransition[(state, '')]:
                    if nextState not in closure:
                        closure.add(nextState)
                        stack.append(nextState)
        return closure

    def subsetConstruction(self):
        
        startClosure = frozenset(self.epsilonClosure({self.nfaStart}))
        self.dfaStart = startClosure
        self.dfaStates.append(startClosure)
        unprocessed = deque([startClosure])
        dfa_trans = {}
        state_counter = 0
        
        self.stateMapping[startClosure] = f"S{state_counter}"
        state_counter += 1

        while unprocessed:
            current = unprocessed.popleft()
            for symbol in self.nfaAlphabet:
                if symbol == '':  
                    continue
                next_states = set()
                for state in current:
                    if (state, symbol) in self.nfaTransition:
                        for nextState in self.nfaTransition[(state, symbol)]:
                            next_states |= self.epsilonClosure({nextState})
                next_states = frozenset(next_states)
                if next_states:
                    if next_states not in self.stateMapping:
                        self.stateMapping[next_states] = f"S{state_counter}"
                        state_counter += 1
                        self.dfaStates.append(next_states)
                        unprocessed.append(next_states)
                    dfa_trans[(current, symbol)] = next_states

        self.dfaTranstion = dfa_trans
        self.dfaAccept = {state for state in self.dfaStates if any(s in self.nfaAccept for s in state)}

    def displayDfa(self):
        
        print("DFA States:")
        for state, label in self.stateMapping.items():
            print(f"{label}: {set(state)}")
        
        print("\nDFA Start State:")
        print(self.stateMapping[self.dfaStart])
        
        print("\nDFA Accept States:")
        accept_states = [self.stateMapping[state] for state in self.dfaAccept]
        print(accept_states)

        print("\nDFA Transitions:")
        table = []
        for (state, symbol), nextState in self.dfaTranstion.items():
            table.append([
                self.stateMapping[state],  
                symbol,                    
                self.stateMapping[nextState]  
            ])
        print(tabulate(table, headers=["Current State", "Input Symbol", "Next State"], tablefmt="grid"))


nfaStates = {'q0', 'q1', 'q2'}
nfaAlphabet = set("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_")
nfaStart = 'q0'
nfaAccept = {'q2'}
nfaStates = {'q0', 'q1', 'q2'}
nfaAlphabet = set("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_")
nfaStart = 'q0'
nfaAccept = {'q2'}
nfaTransition = defaultdict(set)

# Add transitions for starting characters (letters)
for char in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
    nfaTransition[('q0', char)].add('q1')

# Add transitions for continuation characters (letters, digits, underscores)
for char in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_":
    nfaTransition[('q1', char)].add('q1')

# Add epsilon transition to the accept state
nfaTransition[('q1', '')].add('q2')

dfa = DFA(nfaStates, nfaAlphabet, nfaStart, nfaAccept, nfaTransition)
dfa.subsetConstruction()
dfa.displayDfa()
