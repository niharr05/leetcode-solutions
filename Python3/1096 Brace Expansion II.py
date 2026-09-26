class Solution:

    def braceExpansionII(self, expression: str) -> list[str]:
        stack = []
        total_union = set()
        curr_product = {""}

        for char in expression:
            if char.isalpha():
                # Multiply the current running group with the single letter set
                curr_product = {
                    p + char for p in curr_product
                }  #[cite: 29]

            elif char == "{":
                # Push current scope state to stack and reset
                stack.append((total_union, curr_product))  #[cite: 29]
                total_union = set()  #[cite: 29]
                curr_product = {""}  #[cite: 29]

            elif char == ",":
                # Flush curr_product to total_union and start a new product branch
                total_union |= curr_product  #[cite: 29]
                curr_product = {""}  #[cite: 29]

            elif char == "}":
                # Complete the inner scope's full union set
                sub_res = total_union | curr_product  #[cite: 29]

                # Restore previous scope from stack
                prev_union, prev_product = stack.pop()  #[cite: 29]

                # Multiply inner scope result with the outer scope's running product
                curr_product = {
                    p + s for p in prev_product for s in sub_res
                }  #[cite: 29]
                total_union = prev_union  #[cite: 29]

        # Final union of remaining items sorted lexicographically
        return sorted(list(total_union | curr_product))  #[cite: 29]