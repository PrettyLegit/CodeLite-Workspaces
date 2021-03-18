.PHONY: clean All

All:
	@echo "----------Building project:[ A7_Queues - Debug ]----------"
	@cd "A7_Queues" && "$(MAKE)" -f  "A7_Queues.mk"
clean:
	@echo "----------Cleaning project:[ A7_Queues - Debug ]----------"
	@cd "A7_Queues" && "$(MAKE)" -f  "A7_Queues.mk" clean
