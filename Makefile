.PHONY: clean All

All:
	@echo "----------Building project:[ A9_Part1_Trees - Debug ]----------"
	@cd "A9_Part1_Trees" && "$(MAKE)" -f  "A9_Part1_Trees.mk"
clean:
	@echo "----------Cleaning project:[ A9_Part1_Trees - Debug ]----------"
	@cd "A9_Part1_Trees" && "$(MAKE)" -f  "A9_Part1_Trees.mk" clean
