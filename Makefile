.PHONY: clean All

All:
	@echo "----------Building project:[ A9_Part0_Trees - Debug ]----------"
	@cd "A9_Part0_Trees" && "$(MAKE)" -f  "A9_Part0_Trees.mk"
clean:
	@echo "----------Cleaning project:[ A9_Part0_Trees - Debug ]----------"
	@cd "A9_Part0_Trees" && "$(MAKE)" -f  "A9_Part0_Trees.mk" clean
