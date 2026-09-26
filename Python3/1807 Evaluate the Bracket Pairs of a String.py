class Solution:

    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        # Convert knowledge into a hash map for O(1) lookups
        k_map = dict(knowledge)

        result = []
        curr_key = []
        in_bracket = False

        for char in s:
            if char == "(":
                in_bracket = True
            elif char == ")":
                key = "".join(curr_key)
                # Lookup key in map; substitute '?' if missing
                result.append(k_map.get(key, "?"))
                curr_key = []
                in_bracket = False
            elif in_bracket:
                curr_key.append(char)
            else:
                result.append(char)

        return "".join(result)