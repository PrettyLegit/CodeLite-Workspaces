.PHONY: clean All

All:
	@echo "----------Building project:[ A8_E3_Recursion - Debug ]----------"
	@cd "A8_E3_Recursion" && "$(MAKE)" -f  "A8_E3_Recursion.mk"
clean:
	@echo "----------Cleaning project:[ A8_E3_Recursion - Debug ]----------"
	@cd "A8_E3_Recursion" && "$(MAKE)" -f  "A8_E3_Recursion.mk" clean
