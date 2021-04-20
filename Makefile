.PHONY: clean All

All:
	@echo "----------Building project:[ z_LB_a11 - Debug ]----------"
	@cd "z_LB_a11" && "$(MAKE)" -f  "z_LB_a11.mk"
clean:
	@echo "----------Cleaning project:[ z_LB_a11 - Debug ]----------"
	@cd "z_LB_a11" && "$(MAKE)" -f  "z_LB_a11.mk" clean
