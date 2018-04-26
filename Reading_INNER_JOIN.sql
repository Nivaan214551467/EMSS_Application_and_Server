SELECT employee.*
,(GROUP_CONCAT(`equipment`.`equip_id` ORDER BY `equipment`.`equip_id` ASC SEPARATOR ', ')) AS 'Equipment Loaned Out'
FROM `emss_database`.`employee`
LEFT JOIN `emss_database`.`equipment` ON `employee`.`employee_id` = `equipment`.`loaned_out_to`
GROUP BY 1;