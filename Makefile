.PHONY: clean All

All:
	@echo "----------Building project:[ A8_E2_Recursion - Debug ]----------"
	@cd "A8_E2_Recursion" && "$(MAKE)" -f  "A8_E2_Recursion.mk"
clean:
	@echo "----------Cleaning project:[ A8_E2_Recursion - Debug ]----------"
	@cd "A8_E2_Recursion" && "$(MAKE)" -f  "A8_E2_Recursion.mk" clean
