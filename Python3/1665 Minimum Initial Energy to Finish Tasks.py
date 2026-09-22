class Solution:

    def minimumEffort(self, tasks: list[list[int]]) -> int:
        # Sort tasks by (minimum - actual) in descending order
        tasks.sort(key=lambda t: t[1] - t[0], reverse=True)

        total_energy = 0
        current_energy = 0

        for actual, minimum in tasks:
            # If current energy isn't enough to start the task, top up
            if current_energy < minimum:
                total_energy += minimum - current_energy
                current_energy = minimum

            # Spend the actual energy for the task
            current_energy -= actual

        return total_energy