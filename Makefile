.PHONY: clean All

All:
	@echo "----------Building project:[ A12_Graphs - Debug ]----------"
	@cd "A12_Graphs" && "$(MAKE)" -f  "A12_Graphs.mk"
clean:
	@echo "----------Cleaning project:[ A12_Graphs - Debug ]----------"
	@cd "A12_Graphs" && "$(MAKE)" -f  "A12_Graphs.mk" clean
