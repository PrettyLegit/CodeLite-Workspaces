.PHONY: clean All

All:
	@echo "----------Building project:[ A10_Part1_Heaps - Debug ]----------"
	@cd "A10_Part1_Heaps" && "$(MAKE)" -f  "A10_Part1_Heaps.mk"
clean:
	@echo "----------Cleaning project:[ A10_Part1_Heaps - Debug ]----------"
	@cd "A10_Part1_Heaps" && "$(MAKE)" -f  "A10_Part1_Heaps.mk" clean
