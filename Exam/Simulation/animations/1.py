from manimlib import *
from manimlib.animation.creation import ShowCreation  # Correct import

class ZeroReplacement(Scene):
    def construct(self):
        # Title
        title = Text("Zero Replacement and Sorting Check").to_edge(UP)
        self.play(Write(title))

        # First Input visualization
        n, k = 4, 2
        array = [11, 0, 0, 14]
        b = [5, 4]
        input_text = Text(f"Input:\nn={n}, k={k}\na={array}\nb={b}").next_to(title, DOWN)
        self.play(Write(input_text))
        self.wait(1)

        # Highlight zero positions
        zero_indices = [i for i, x in enumerate(array) if x == 0]
        zero_highlight = SurroundingRectangle(input_text, color=RED)
        self.play(ShowCreation(zero_highlight))
        self.wait(1)
        self.play(FadeOut(zero_highlight))  # Remove the highlight after use

        # Phase 1: k = 1
        if k == 1:
            b_sorted = sorted(b, reverse=True)
            for i, idx in enumerate(zero_indices):
                array[idx] = b_sorted[i]
            updated_array_text = Text(f"Updated Array: {array}").next_to(input_text, DOWN)
            self.play(Transform(input_text, updated_array_text))
            self.wait(1)

            # Check if the array is not sorted
            is_sorted = all(array[i] <= array[i + 1] for i in range(len(array) - 1))
            result_text = Text(f"Result: {'Yes' if not is_sorted else 'No'}").next_to(updated_array_text, DOWN)
            self.play(Write(result_text))
            self.wait(2)

        # Phase 2: k > 1
        else:
            result_text = Text("Result: Yes (k > 1)").next_to(input_text, DOWN)
            self.play(Write(result_text))
            self.wait(2)
            updated_array_text = None  # Ensure updated_array_text is defined

        # Repeat with new input
        fadeout_animations = [FadeOut(result_text), FadeOut(input_text)]
        if updated_array_text:  # Only add if updated_array_text is defined
            fadeout_animations.append(FadeOut(updated_array_text))
        self.play(*fadeout_animations)

        n, k = 4, 1
        array = [8, 94, 0, 4]
        b = [89]
        input_text = Text(f"Input:\nn={n}, k={k}\na={array}\nb={b}").next_to(title, DOWN)
        self.play(Write(input_text))
        self.wait(1)

        # Highlight zero positions
        zero_indices = [i for i, x in enumerate(array) if x == 0]
        zero_highlight = SurroundingRectangle(input_text, color=RED)
        self.play(ShowCreation(zero_highlight))
        self.wait(1)
        self.play(FadeOut(zero_highlight))  # Remove the highlight after use

        # Phase 1: k = 1
        if k == 1:
            b_sorted = sorted(b, reverse=True)
            for i, idx in enumerate(zero_indices):
                array[idx] = b_sorted[i]
            updated_array_text = Text(f"Updated Array: {array}").next_to(input_text, DOWN)
            self.play(Transform(input_text, updated_array_text))
            self.wait(1)

            # Check if the array is not sorted
            is_sorted = all(array[i] <= array[i + 1] for i in range(len(array) - 1))
            result_text = Text(f"Result: {'Yes' if not is_sorted else 'No'}").next_to(updated_array_text, DOWN)
            self.play(Write(result_text))
            self.wait(2)
        else:
            result_text = Text("Result: Yes (k > 1)").next_to(input_text, DOWN)
            self.play(Write(result_text))
            self.wait(2)
            updated_array_text = None  # Ensure updated_array_text is defined

        # Repeat with new input
        fadeout_animations = [FadeOut(result_text), FadeOut(input_text)]
        if updated_array_text:  # Only add if updated_array_text is defined
            fadeout_animations.append(FadeOut(updated_array_text))
        self.play(*fadeout_animations)

        # Third Input visualization
        n, k = 6, 1
        array = [2, 3, 0, 8, 9, 10]
        b = [5]
        input_text = Text(f"Input:\nn={n}, k={k}\na={array}\nb={b}").next_to(title, DOWN)
        self.play(Write(input_text))
        self.wait(1)

        # Highlight zero positions
        zero_indices = [i for i, x in enumerate(array) if x == 0]
        zero_highlight = SurroundingRectangle(input_text, color=RED)
        self.play(ShowCreation(zero_highlight))
        self.wait(1)
        self.play(FadeOut(zero_highlight))  # Remove the highlight after use

        # Phase 1: k = 1
        if k == 1:
            b_sorted = sorted(b, reverse=True)
            for i, idx in enumerate(zero_indices):
                array[idx] = b_sorted[i]
            updated_array_text = Text(f"Updated Array: {array}").next_to(input_text, DOWN)
            self.play(Transform(input_text, updated_array_text))
            self.wait(1)

            # Check if the array is not sorted
            is_sorted = all(array[i] <= array[i + 1] for i in range(len(array) - 1))
            result_text = Text(f"Result: {'Yes' if not is_sorted else 'No'}").next_to(updated_array_text, DOWN)
            self.play(Write(result_text))
            self.wait(2)
        else:
            result_text = Text("Result: Yes (k > 1)").next_to(input_text, DOWN)
            self.play(Write(result_text))
            self.wait(2)
            updated_array_text = None  # Ensure updated_array_text is defined