from manimlib import *

class PerfectNumberCount(Scene):
    def construct(self):
        # Title
        title = Text("Perfect Numbers Count in Range", font_size=32).to_edge(UP)
        self.play(Write(title))

        # Input visualization
        m, n = 10, 500
        input_text = Text(f"Input:\nm={m}, n={n}", font_size=24).next_to(title, DOWN)
        self.play(Write(input_text))
        self.wait(1)

        # Perfect numbers list
        perfect_numbers = [6, 28, 496, 8128, 33550336, 8589869056, 137438691328]
        perfect_numbers_text = VGroup(
            *[Text(str(num), font_size=24) for num in perfect_numbers]
        ).arrange(RIGHT, buff=0.5).next_to(input_text, DOWN * 7)  # 下移数组
        self.play(Write(perfect_numbers_text))
        self.wait(1)

        # Arrow for visualization
        arrow = Arrow(start=UP, end=DOWN, color=BLUE, buff=0.1).scale(0.3)
        arrow.next_to(perfect_numbers_text[0], UP)
        self.play(ShowCreation(arrow))
        self.wait(1)

        # Find range indices with visualization
        b = next((i for i, num in enumerate(perfect_numbers) if num >= m), len(perfect_numbers))
        b_label = Text("", font_size=24).next_to(arrow, UP)
        self.play(Write(b_label))
        for i in range(len(perfect_numbers)):
            arrow.next_to(perfect_numbers_text[i], UP)
            new_label = Text(f"Checking: {perfect_numbers[i]}", font_size=24).next_to(arrow, UP)
            self.play(Transform(b_label, new_label), run_time=0.5)
            if i == b:
                break
        b_text = Text(f"First index >= {m}: {b}", font_size=24).next_to(perfect_numbers_text, DOWN * 2)  # 下移文字
        self.play(Write(b_text))
        self.wait(1)

        e = next((i for i, num in enumerate(perfect_numbers) if num > n), len(perfect_numbers))
        for i in range(b, len(perfect_numbers)):
            arrow.next_to(perfect_numbers_text[i], UP)
            new_label = Text(f"Checking: {perfect_numbers[i]}", font_size=24).next_to(arrow, UP)
            self.play(Transform(b_label, new_label), run_time=0.5)
            if i == e:
                break
        e_text = Text(f"First index > {n}: {e}", font_size=24).next_to(b_text, DOWN * 2)  # 下移文字
        self.play(Write(e_text))
        self.wait(1)

        # Count perfect numbers in range
        count = max(0, e - b)
        result_text = Text(f"Perfect Numbers Count: {count}", font_size=24).next_to(e_text, DOWN * 2)  # 下移文字
        self.play(Write(result_text))
        self.wait(2)
