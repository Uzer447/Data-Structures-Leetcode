class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        area = 0
        min_x = min_y = float('inf')
        max_x = max_y = float('-inf')
        corners = set()
        
        for rect in rectangles:
            x1, y1, x2, y2 = rect
            # Update bounding rectangle
            min_x = min(min_x, x1)
            min_y = min(min_y, y1)
            max_x = max(max_x, x2)
            max_y = max(max_y, y2)
            
            # Calculate area
            rect_area = (x2 - x1) * (y2 - y1)
            area += rect_area
            
            # Process corners
            rect_corners = [(x1,y1), (x1,y2), (x2,y1), (x2,y2)]
            for corner in rect_corners:
                if corner in corners:
                    corners.remove(corner)
                else:
                    corners.add(corner)
        
        # Total area of bounding rectangle
        bounding_area = (max_x - min_x) * (max_y - min_y)
        
        # Check if total area matches
        if area != bounding_area:
            return False
        
        # Check if corners set has exactly four corners
        if len(corners) != 4:
            return False
        
        # Check if corners are the corners of bounding rectangle
        expected_corners = [(min_x, min_y), (min_x, max_y), (max_x, min_y), (max_x, max_y)]
        for corner in expected_corners:
            if corner not in corners:
                return False
        
        return True